#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::string> arr;
std::string s;
size_t n, m;

bool one_point() {
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
                return true;
            }
        }
    }
    return false;
}

bool two_points() {
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
                return true;
            }
        }
    }
    return false;
}

bool many_points() {
    bool ok = false;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            bool cur = true;
            for (int pos = 0; pos < n; pos++) {
                if ((arr[i][pos] != s[pos]) && (arr[j][pos] != s[pos])) cur = false;
            }
            ok |= cur;
        }
    }
    return ok;
}

int main() {
    freopen("crossover.in", "r", stdin);
    freopen("crossover.out", "w", stdout);

    std::cin >> m >> n;
    for (size_t i = 0; i < m; ++i) {
        std::string loc;
        std::cin >> loc;
        arr.push_back(loc);
    }
    std::cin >> s;

    if (std::find(arr.begin(), arr.end(), s) != arr.end() || one_point()) {
        std::cout << "YES\nYES\nYES\n";
    } else {
        if (two_points()) {
            std::cout << "NO\nYES\nYES\n";
        } else {
            if (many_points()) {
                std::cout << "NO\nNO\nYES\n";
            } else {
                std::cout << "NO\nNO\nNO\n";
            }
        }
    }

    return 0;
}