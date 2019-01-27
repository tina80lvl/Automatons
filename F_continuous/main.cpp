#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

const int LEN = 250 + 10;
const double EPS = 1e-8;

int main() {
	freopen("continuous.in", "r", stdin);
	freopen("continuous.out", "w", stdout);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> tree(n);
    std::vector<int> length(m), has(2 * n);
    std::vector<std::string> in(m);
    std::vector<std::vector<double>> out(m, std::vector<double> (LEN)),
                                     gauss(2 * n, std::vector<double> (2 * n));
    std::vector<double> res(2 * n);

	for (size_t i = 0; i < n; ++i) {
		std::cin >> tree[i].first >> tree[i].second;
		--tree[i].first; --tree[i].second;
	}

	for (size_t i = 0; i < m; ++i) {
		std::cin >> length[i];
		std::cin >> in[i];
		for (size_t j = 0; j < length[i]; ++j) {
			std::cin >> out[i][j];
		}
	}

    for (size_t i = 0; i < 2 * n; ++i) {
        res[i] = 0.0;
        for (size_t j = 0; j < 2 * n; ++j) {
            gauss[i][j] = 0.0;
        }
    }
    for (size_t k = 0; k < 2 * n; ++k) {
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < 2 * n; ++j) {
                has[j] = 0;
            }
            int v = 0,
                len = length[i];
            for (size_t j = 0; j < len; ++j) {
                int next = in[i][j] - '0';
                ++has[2 * v + next];
                if (has[k] > 0) {
                    res[k] += 2 * out[i][j] / len * has[k];
                    for (size_t h = 0; h < 2 * n; ++h) {
                        if (has[h] > 0) {
                            gauss[k][h] += 2 * (double)has[h] / len * has[k];
                        }
                    }
                }
                if (next) {
                    v = tree[v].second;
                } else {
                    v = tree[v].first;
                }
            }
        }
    }

    for (size_t i = 0; i < 2 * n; ++i) {
        if (fabs(gauss[i][i]) < EPS) {
            bool ok = false;
            for (size_t k = i + 1; k < 2 * n; ++k) {
                if (ok) {
                    break;
                }
                if (fabs(gauss[k][i]) > EPS) {
                    ok = true;
                    for (int h = 0; h < 2 * n; ++k) {
                        std::swap(gauss[i][h], gauss[k][h]);
                    }
                }
            }
            if (!ok) {
                for (size_t k = 0; k < 2 * n; ++k) {
                    gauss[i][k] = 0.0;
                }
                res[i] = 0.0;
                gauss[i][i] = 1.0;
            }
        }
        double cur = gauss[i][i];
        for (size_t k = 0; k < 2 * n; ++k) {
            gauss[i][k] /= cur;
        }
        res[i] /= cur;
        for (size_t j = i + 1; j < 2 * n; ++j) {
            double val = gauss[j][i];
            for (size_t k = 0; k < 2 * n; ++k) {
                gauss[j][k] -= val * gauss[i][k];
            }
            res[j] -= val * res[i];
        }
    }

    for (int i = (int)(2 * n - 1); i >= 0; --i) {
        for (size_t j = 0; j < i; ++j) {
            double val = gauss[j][i];
            for (int k = 0; k < 2 * n; ++k) {
                gauss[j][k] -= val * gauss[i][k];
            }
            res[j] -= val * res[i];
        }
    }

	std::cout.precision(8);
	for (size_t i = 0; i < n; ++i) {
		std::cout << res[2 * i] << " " << res[2 * i + 1] << std::endl;
	}

}