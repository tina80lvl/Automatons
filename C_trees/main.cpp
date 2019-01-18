#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int n;
std::vector <int> tree2, color;
std::map<int, int> pred;

struct vertex {
    int p;
    int l;
    int r;
    int prev;
    int num;
    vertex() {
        prev = -1;
    }
    vertex(int a, int b, int c, int d, int e) {
        p = a;
        l = b;
        r = c;
        num = d;
        prev = e;
    }
};

std::vector <vertex> tree;

void dfs(int v) {
    if (v == -1) {
        return;
    }
    if (tree[v].l == -1) {
        return;
    }
    color[v] = 1;
    if (pred.find(tree[v].p) != pred.end() && pred[tree[v].p] != -1) {
        int pp = pred[tree[v].p], cur = tree[v].r;
        if (color[tree[pp].l] == 1) {
            cur = tree[v].l;
        }
        if (tree[tree[v].prev].l == v) {
            tree[tree[v].prev].l = cur;
        } else {
            tree[tree[v].prev].r = cur;
        }
        tree[cur].prev = tree[v].prev;
        dfs(cur);
    } else {
        pred[tree[v].p] = v;
        dfs(tree[v].l);
        dfs(tree[v].r);
        pred[tree[v].p] = -1;
    }
    color[v] = 2;
}

int renum(int v, int num) {
    tree2[num] = v;
    tree[v].num = num;
    if (tree[v].l == -1)
        return 1;
    int cnt = renum(tree[v].l, num + 1);
    return cnt + renum(tree[v].r, num + cnt + 1) + 1;
}

int main() {
    freopen("trees.in", "r", stdin);
    freopen("trees.out", "w", stdout);

    std::cin >> n;
    tree.assign(n, vertex());
    tree2.assign(n, 0);
    color.assign(n, 0);

    char s[20];
    for (int i = 0; i < n; ++i) {
        color[i] = 0;
        std::cin >> s;
        if (s[0] == 'l') {
            int p;
            std::cin >> p;
            tree[i] = vertex(p, -1, -1, i, tree[i].prev);
        } else {
            int p, l, r;
            std::cin >> p >> l >> r;
            --l;
            --r;
            tree[i] = vertex(p, l, r, i, tree[i].prev);
            tree[l].prev = i;
            tree[r].prev = i;
        }
    }
    dfs(0);
    int cnt = renum(0, 0);
    std::cout << cnt << std::endl;

    for (int i = 0; i < cnt; ++i) {
        int v = tree2[i];
        if (tree[v].l == -1) {
            std::cout << "leaf " << tree[v].p << std::endl;
        } else {
            std::cout << "choice " << tree[v].p << " " << tree[tree[v].l].num + 1 << " " << tree[tree[v].r].num + 1 << std::endl;
        }
    }

    return 0;
}