#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par, siz;
    vector<unordered_set<int>> child;
    UnionFind(int n) : par(n, -1), siz(n, 1), child(n) {
        for (int i = 0; i < n; ++i) child[i].insert(i);
    }

    int root(int x) {
        if (par[x] == -1)   return x;
        else    return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y])    swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        child[x].insert(y);
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int n, k, l; cin >> n >> k >> l;
    UnionFind road(n+1), rail(n+1);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        road.unite(a, b);
    }
    for (int i = 0; i < l; ++i) {
        int a, b;
        cin >> a >> b;
        rail.unite(a, b);
    }
    
    map<pair<int, int>, int> m;
    for (int v = 1; v <= n; ++v) {
        pair<int, int> p(road.root(v), rail.root(v));
        m[p]++;
    }
    for (int v = 1; v <= n; ++v) {
        pair<int, int> p(road.root(v), rail.root(v));
        cout << m[p] << " ";
    }
    cout << endl;
}