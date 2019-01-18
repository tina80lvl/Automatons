#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    freopen("mutation.in", "r", stdin);
    freopen("mutation.out", "w", stdout);

    size_t n, m;
    std::cin >> n >> m;

    for (size_t ind = 0; ind < m; ++ind) {
        std::string a, b;
        std::cin >> a;
        std::cin >> b;
        double p = 1.0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                p /= (double)n;
            } else {
                p *= (double)(n - 1) / (double)n;
            }
        }
        std::cout << std::setprecision(10) << p << std::endl;
    }

    return 0;
}