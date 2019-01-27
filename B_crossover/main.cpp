#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

int main() {
    freopen("crossover.in", "r", stdin);
    freopen("crossover.out", "w", stdout);

    std::string s, trash;
    size_t n, m;
    std::cin >> m >> n;
    getline(std::cin, trash);

    std::vector<std::string> arr(m);
    for (size_t i = 0; i < m; ++i) {
        getline(std::cin, arr[i]);
    }
    getline(std::cin, s);

    bool isFound = std::find(arr.begin(), arr.end(), s) != arr.end(), is1point = false, is2points = false, isNpoints = false;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < m; ++j) {
            int pos = 0;
            while (pos < n && s[pos] == arr[i][pos]) {
                ++pos;
            }
            while (pos < n && s[pos] == arr[j][pos]) {
                ++pos;
            }
            if (pos == n) {
                is1point = true;
                break;
            }
        }
        if (is1point) break;
    }


    if (isFound || is1point) {
        std::cout << "YES\nYES\nYES\n";
        return 0;
    } else {
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < m; ++j) {
                int pos = 0;
                while (pos < n && s[pos] == arr[i][pos]) {
                    pos++;
                }
                while (pos < n && s[pos] == arr[j][pos]) {
                    pos++;
                }
                while (pos < n && s[pos] == arr[i][pos]) {
                    pos++;
                }
                if (pos == n) {
                    is2points = true;
                    break;
                }
            }
            if (is2points) {
                std::cout << "NO\nYES\nYES\n";
                return 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                bool cur = true;
                for (int pos = 0; pos < n; pos++) {
                    if ((arr[i][pos] != s[pos]) && (arr[j][pos] != s[pos])) cur = false;
                }
                isNpoints |= cur;
            }
        }
        if (isNpoints) {
            std::cout << "NO\nNO\nYES\n";
        } else {
            std::cout << "NO\nNO\nNO\n";
        }
    }

    return 0;
}