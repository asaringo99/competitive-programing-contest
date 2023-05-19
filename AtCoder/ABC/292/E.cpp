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
#define all(a) a.begin(), a.end()
#define endl "\n"

int n, m;
vector<int> G[2020];
set<int> B[2020];
bool used[2020][2020];

void dfs(int s, int v, int prev){
    used[s][v] = true;
    B[s].insert(v);
    for(int u : G[v]){
        B[s].insert(u);
        if(u == prev) continue;
        if(used[s][u]) continue;
        dfs(s,u,v);
    }
}

int main(){
    fast_io
    cin >> n >> m;
    if(m == 0){
        cout << 0 << endl;
        return 0;
    }
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
    }
    ll res = 0;
    rep(i,n){
        dfs(i,i,-1);
        for(int u : G[i]){
            B[i].erase(u);
        }
        res += B[i].size() - 1;
    }
    cout << res << endl;
}