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

int z ;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n,0);
    vector<set<int>> G(n);
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].insert(v) ;
        G[v].insert(u) ;
    }
    queue<int> que;
    rep(i,n){
        if(G[i].size() == 1){
            que.push(i);
        }
    }
    int res = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int u : G[v]){
            ++A[u];
            res += A[u] / k;
            A[u] %= k;
            G[u].erase(v);
            if(G[u].size() == 1 && A[u] == 0){
                que.push(u);
            }
        }
    }
    rep(i,n) res += A[i] / k;
    cout << res << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}