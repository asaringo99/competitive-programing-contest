#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
//---------------------------------------------------------------------------------------------------
typedef long long ll;
#define def 0
using V = ll;
V comp(V& l, V& r) { return max(l,r); };
struct SegTree { //[l,r)
    int NV;
    vector<V> val;
    void init(int n) {
        NV = 1;
        while (NV < n) NV *= 2;
        val = vector<V>(NV * 2, def);
    }
    V get(int x, int y, int l, int r, int k) {
        if (r <= x || y <= l) return def; if (x <= l&&r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); auto b = get(x, y, (l + r) / 2, r, k * 2 + 1); return comp(a, b);
    }
    V get(int x, int y) { return get(x, y, 0, NV, 1); }
    void update(int i, V v) { i += NV; val[i] = v; while (i>1)i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]); }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};

struct Healthy2DSegTree {
    int NV;
    vector<SegTree> st;
    vector<vector<int>> index;
    
    void init(vector<vector<int>> &v) {
        int n = v.size();
        NV = 1; while (NV < n) NV *= 2;
        index.resize(2 * NV);
        rep(i, 0, n) fore(j, v[i]) index[i + NV].push_back(j);
        rrep(i, NV * 2 - 1, 1) {
            sort(index[i].begin(), index[i].end());
            index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
            fore(j, index[i]) index[i / 2].push_back(j);
        }
        st.resize(2 * NV);
        rep(i, 1, NV * 2) st[i].init(index[i].size());
    }
    void update(int x, int y, V v) {
        assert(x < NV);
        //x += NV;
        x = NV;
        while (x) {
            int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
            assert(yy != index[x].size());
            assert(y == index[x][yy]);
            st[x].update(yy, v);
            x >>= 1;
        }
    }
    void add(int x, int y, V v) {
        assert(x < NV);
        //x += NV;
        x = NV;
        while (x) {
            int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
            assert(yy != index[x].size());
            assert(y == index[x][yy]);
            st[x].add(yy, v);
            x >>= 1;
        }
    }
    V get(int sx, int tx, int sy, int ty, int k, int l, int r) {
        assert(k < NV * 2);
        assert(l < r);
        if (r <= sx or tx <= l) return def;
        if (sx <= l and r <= tx) {
            int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
            int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
            return st[k].get(syy, tyy);
        }
        int md = (l + r) / 2;
        V le = get(sx, tx, sy, ty, k * 2, l, md);
        V ri = get(sx, tx, sy, ty, k * 2 + 1, md, r);
        return comp(le, ri);
    }
    V get(int sx, int tx, int sy, int ty) {
        return get(sx, tx, sy, ty, 1, 0, NV);
    }
};

int H, W, Q;
vector<vector<int>> query;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> H >> W >> Q;
    rep(i, 0, Q) {
        int t; cin >> t;
        if (t == 1) {
            int x, y, v; cin >> x >> y >> v;
            query.push_back({ t, x, y, v });
        }
        else {
            int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
            query.push_back({ t, sx, sy, tx, ty });
        }
    }

    Healthy2DSegTree st;
    vector<vector<int>> index(W);
    rep(i, 0, Q) {
        ll t , x , y ;
        if(t == 0) st.add()
        ll ans = st.get(0 , H , 0 , W);
    }
    st.init(index);

    rep(i, 0, Q) {
        if (query[i][0] == 1) {
            int x = query[i][1];
            int y = query[i][2];
            int v = query[i][3];
            st.add(x, y, v);
        } else {
            int sx = query[i][1];
            int sy = query[i][2];
            int tx = query[i][3];
            int ty = query[i][4];
            ll ans = st.get(sx, tx + 1, sy, ty + 1);
            printf("%lld\n", ans);
        }
    }
}