#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
// #define all(a) a.begin(), a.end()

template< typename G >
struct HeavyLightDecomposition {
  G &g;
  vector< int > sz, in, out, head, rev, par;

  HeavyLightDecomposition(G &g) :
      g(g), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()) {}

  void dfs_sz(int idx, int p) {
    par[idx] = p;
    sz[idx] = 1;
    if(g[idx].size() && g[idx][0] == p) swap(g[idx][0], g[idx].back());
    for(auto &to : g[idx]) {
      if(to == p) continue;
      dfs_sz(to, idx);
      sz[idx] += sz[to];
      if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to);
    }
  }

  void dfs_hld(int idx, int par, int &times) {
    in[idx] = times++;
    rev[in[idx]] = idx;
    for(auto &to : g[idx]) {
      if(to == par) continue;
      head[to] = (g[idx][0] == to ? head[idx] : to);
      dfs_hld(to, idx, times);
    }
    out[idx] = times;
  }

  void build() {
    dfs_sz(0, -1);
    int t = 0;
    dfs_hld(0, -1, t);
  }

  int la(int v, int k) {
    while(1) {
      int u = head[v];
      if(in[v] - k >= in[u]) return rev[in[v] - k];
      k -= in[v] - in[u] + 1;
      v = par[u];
    }
  }

  int lca(int u, int v) {
    for(;; v = par[head[v]]) {
      if(in[u] > in[v]) swap(u, v);
      if(head[u] == head[v]) return u;
    }
  }

  template< typename T, typename Q, typename F >
  T query(int u, int v, const T &ti, const Q &q, const F &f, bool edge = false) {
    T l = ti, r = ti;
    for(;; v = par[head[v]]) {
      if(in[u] > in[v]) swap(u, v), swap(l, r);
      if(head[u] == head[v]) break;
      l = f(q(in[head[v]], in[v] + 1), l);
    }
    return f(f(q(in[u] + edge, in[v] + 1), l), r);
//  return {f(q(in[u] + edge, in[v] + 1), l), r};
  }

  template< typename Q >
  void add(int u, int v, const Q &q, bool edge = false) {
    for(;; v = par[head[v]]) {
      if(in[u] > in[v]) swap(u, v);
      if(head[u] == head[v]) break;
      q(in[head[v]], in[v] + 1);
    }
    q(in[u] + edge, in[v] + 1);
  }
};

#define endl "\n"
using int64 = long long;
const int64 INF = 1LL << 55;
 
struct State {
  int64 ans, all, left, right;
 
  State() : ans(-INF), all(0), left(-INF), right(-INF) {}
 
  State(int64 val, int length) {
    all = val * length;
    ans = left = right = (val > 0 ? all : val);
  }
 
  State operator+(const State &s) const {
    State ret;
    ret.ans = max({ans, s.ans, right + s.left});
    ret.all = all + s.all;
    ret.left = max(left, all + s.left);
    ret.right = max(s.right, right + s.all);
    return (ret);
  }
};
 
 
struct SegmentTree {
  vector< State > seg;
  vector< int64 > lazy;
  int sz;
 
  SegmentTree(int n) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, State());
    lazy.assign(2 * sz - 1, INF);
  }
 
  void push(int k, int l, int r) {
    if(lazy[k] == INF) return;
    seg[k] = State(lazy[k], r - l);
    if(k < sz - 1) {
      lazy[2 * k + 1] = lazy[k];
      lazy[2 * k + 2] = lazy[k];
    }
    lazy[k] = INF;
  }
 
  void update(int a, int b, int x, int k, int l, int r) {
    push(k, l, r);
    if(a >= r || b <= l) {
      return;
    }
    if(a <= l && r <= b) {
      lazy[k] = x;
      push(k, l, r);
      return;
    }
    update(a, b, x, 2 * k + 1, l, (l + r) >> 1);
    update(a, b, x, 2 * k + 2, (l + r) >> 1, r);
    seg[k] = seg[2 * k + 1] + seg[2 * k + 2];
  }
 
  State query(int a, int b, int k, int l, int r) {
    push(k, l, r);
    if(a >= r || b <= l) return (State());
    if(a <= l && r <= b) return (seg[k]);
    return (query(a, b, 2 * k + 1, l, (l + r) >> 1) +
            query(a, b, 2 * k + 2, (l + r) >> 1, r));
  }
 
  void update(int a, int b, int x) {
    update(a, b, x, 0, 0, sz);
  }
 
  State query(int a, int b) {
    return (query(a, b, 0, 0, sz));
  }
 
  void set(int k, int v) {
    seg[k + sz - 1] = State(v, 1);
  }
 
  void build() {
    for(int k = sz - 2; k >= 0; k--) {
      seg[k] = seg[2 * k + 1] + seg[2 * k + 2];
    }
  }
};

struct UnWeightedGraph{
    int to;
    ll cost;
};
 
int main() {
  int N, Q, S[200000];
  scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }
  UnWeightedGraph g(N);
  HeavyLightDecomposition< UnWeightedGraph > tree(g);
  for(int i = 0; i < N - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  tree.build();
  SegmentTree seg(N);
  for(int i = 0; i < N; i++) seg.set(i, S[tree.rev[i]]);
  seg.build();
  while(Q--) {
    int T, A, B, C;
    scanf("%d %d %d %d", &T, &A, &B, &C);
    --A, --B;
    if(T == 1) {
      tree.add(A, B, [&](int a, int b) { seg.update(a, b, C); });
    } else {
      /* l と r をマージせずに返すように実装を変更している */
      auto beet = tree.query(A, B, State(), [&](int a, int b) { return seg.query(a, b); }, [](const State &a, const State &b) { return a + b; });
      swap(beet.first.left, beet.first.right);
      printf("%lld\n", (beet.first + beet.second).ans);
    }
  }
}