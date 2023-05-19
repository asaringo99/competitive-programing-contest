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
vector<int> G[202020];
int from[202020];
int C[202020];

void dfs(int v, int prev){
    from[v] = prev;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v);
    }
}

int main(){
    fast_io
    cin >> n >> m;
    if(n == 1 && m == 0){
        cout << "Yes" << endl;
        return 0;
    }
    if(n - 1 != m){
        cout << "No" << endl;
        return 0;
    }
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    int k = -1;
    rep(i,n) if(G[i].size() == 1) k = i;
    dfs(k,-1);
    rep(i,n) {
        if(from[i] == -1) continue;
        C[from[i]]++;
    }
    rep(i,n){
        if(C[from[i]] > 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}