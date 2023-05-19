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

int n;

int dp[202020][2];
vector<int> G[202020];
int A[202020];
vector<int> vec[2];

void f(int s){
    priority_queue<P,vector<P>,greater<P>> que;
    for(int u : vec[s]) {
        que.push({0,u});
        dp[u][s] = 0;
    }
    while(!que.empty()){
        auto [d, v] = que.top(); que.pop();
        if(dp[v][s] < d) continue;
        for(int u : G[v]){
            if(dp[u][s] > dp[v][s] + 1){
                dp[u][s] = dp[v][s] + 1;
                que.push({dp[u][s],u});
            }
        }
    }
}

void solve(){
    cin >> n;
    rep(i,n) {
        cin >> A[i];
        if(i + A[i] < n) G[i+A[i]].push_back(i);
        if(i - A[i] >= 0) G[i-A[i]].push_back(i);
        vec[A[i]%2].push_back(i);
    }
    rep(i,n) rep(j,2) dp[i][j] = 1e9;
    f(0); f(1);
    rep(i,n){
        int a = A[i] & 1;
        a ^= 1;
        if(dp[i][a] == 1e9) cout << -1 << " ";
        else cout << dp[i][a] << " ";
    }
    cout << endl;
}

int main(){
    fast_input_output
    solve();
}