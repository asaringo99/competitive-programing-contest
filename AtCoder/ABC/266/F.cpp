#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define endl "\n"

int n, q ;

struct UnionFind {
    vector<int> par ; //親
    vector<int> lank ; //木の深さ
    vector<int> volume ; //木のサイズ
    UnionFind(int n){
        //n要素で初期化
        par.resize(n) ;
        lank.resize(n) ;
        volume.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            par[i] = i ;
            lank[i] = 0 ;
            volume[i] = 1 ;
        }
    }
    //木の根を求める
    int root(int x){
        if(par[x] == x){
            return x ;
        } else{
            return par[x] = root(par[x]) ;
        }
    }

    //xとyの属する集合を合併
    void unite(int x , int y){
        x = root(x);
        y = root(y) ;
        if(x == y) return ;

        if(lank[x] < lank[y]){
            par[x] = y ;
            volume[y] += volume[x] ;
        } else {
            par[y] = x ;
            if(lank[x] == lank[y]) lank[x]++ ;
                volume[x] += volume[y] ;
        }
    }

    bool same(int x , int y){
        return root(x) == root(y) ;
    }

    int size(int x){
        return volume[root(x)] ;
    }
} ;

vector<int> G[202020], F[202020];
P A[202020];
bool used[202020];
set<int> st;
int num[202020];
bool ok = false;

void dfs(int v, int prev){
    if(used[v]){
        if(ok) return;
        ok = true;
        rrep(i,1,n+1){
            if(used[i]) st.insert(i);
        }
        return;
    }
    used[v] = true;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v);
    }
    used[v] = false;
}

void dfs(int v, int prev, int val){
    num[v] = val;
    for(int u : F[v]){
        if(u == prev) continue;
        dfs(u,v,val);
    }
}

int main(){
    fast_input_output
    cin >> n ;
    UnionFind uf(n+10);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        A[i] = {a,b};
    }
    int node = -1;
    rep(i,n){
        auto [a,b] = A[i];
        if(uf.same(a,b)){
            node = a;
            break;
        }
        uf.unite(a,b);
    }
    dfs(node,-1);
    rrep(i,1,n+1){
        int v = i;
        if(st.count(v)) v = 0;
        for(int j : G[i]){
            int u = j;
            if(st.count(u)) u = 0;
            if(u == v) continue;
            F[i].push_back(j);
        }
    }

    int cc = 0;
    for(int u : st){
        // cout << u << ": ";
        // for(int v : F[u]) cout << v << " " ; cout << endl;
        dfs(u,-1,cc);
        cc++;
    }
    cin >> q;
    rep(i,q){
        int a,b;
        cin >> a >> b;
        if(st.count(a) && st.count(b)) cout << "No" << endl;
        else{
            if(num[a] == num[b]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}