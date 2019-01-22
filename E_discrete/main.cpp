#include <iostream>
#include <cstdio>
#include <vector>

const int N = 10 + 10,
          M = 2000 + 10,
          MAX_LEN = 10000 + 10;

int main() {
    freopen("discrete.in", "r", stdin);
    freopen("discrete.out", "w", stdout);

    size_t n, m;
    std::cin >> n >> m;

    std::pair<int, int> tree[N];
    char str1[M][MAX_LEN], str2[M][MAX_LEN];
    int length[M];
    int cnt[N][2][27][MAX_LEN];
    char res[N][2];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tree[i].first, &tree[i].second);
        tree[i].first--;
        tree[i].second--;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %s %s", &length[i], str1[i], str2[i]);
    }

    for (int i = 0; i < m; ++i) {
        int v = 0, len = length[i];
        for (int j = 0; j < len; ++j) {
            char c = str2[i][j];
            int next = (str1[i][j] - '0');
            ++cnt[v][next][c - 'a'][len];
            if (next == 0) {
                v = tree[v].first;
            } else {
                v = tree[v].second;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            int sym = 0;
            double mm = -1;
            for (int c = 0; c < 27; ++c) {
                double val = 0;
                for (int len = 1; len < MAX_LEN; ++len) {
                    val += cnt[i][j][c][len] / (double)len;
                }
                if (val > mm) {
                    mm = val;
                    sym = c;
                }
            }
            res[i][j] = (char)('a' + sym);
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%c %c\n", res[i][0], res[i][1]);
    }

    return 0;
}