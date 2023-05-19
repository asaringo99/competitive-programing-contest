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

int n, k;
int A[202];
int dp[202][403], S[403];
vector<int> G[402];

void dfs(int v, int prev, int dep){
    int res = 0;
    dp[v][dep] = A[v];
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v,dep+1);
        rrep(i,dep,401){
            rep(j,401) S[j] = dp[v][j];
            rrep(j,dep,401){
                if(i + j - 2 * dep > k) chmax(S[min(i,j)],dp[v][i]+dp[u][j]);
            }
            rep(j,401) dp[v][j] = S[j];
        }
    }
}

void solve(){
    cin >> n >> k;
    rep(i,n) cin >> A[i];
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfs(0,-1,0);
    int res = 0;
    rep(i,401) chmax(res,dp[0][i]);
    cout << res << endl;
}

int main(){
    fast_input_output
    solve();
}