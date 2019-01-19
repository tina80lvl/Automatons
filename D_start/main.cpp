#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
char s[500500];
std::vector<int> res;
std::vector<std::vector<bool>> dp;

struct vertex {
    int l;
    int r;
    char c;
};

std::vector<vertex> tree;

void ddp() {
    for (int i = 0; i < n; i++) {
        dp[i][m % 2] = true;
    }
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            dp[j][i % 2] = false;
            int left = tree[j].l;
            int right = tree[j].r;
            if (tree[left].c == s[i]) {
                dp[j][i % 2] = (dp[j][i % 2]) | (dp[left][(i + 1) % 2]);
            }
            if (tree[right].c == s[i]) {
                dp[j][i % 2] = (dp[j][i % 2]) | (dp[right][(i + 1) % 2]);
            }
        }
    }
}

int main() {
    freopen("start.in", "r", stdin);
    freopen("start.out", "w", stdout);

    std::cin >> m >> n;

    dp.assign(n, std::vector <bool> (2, false));
    tree.assign(n, vertex());
    for (int i = 0; i < n; ++i) {
        int l, r;
        char c;
        std::cin >> l >> r >> c;
        tree[i] = {--l, --r, c};
    }

    std::cin >> s;
    ddp();
    for (int i = 0; i < n; ++i) {
        if (dp[i][0]) {
            res.push_back(i);
        }
    }
    std::cout << res.size() << " ";
    for (int x: res) {
        std::cout << x + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}
