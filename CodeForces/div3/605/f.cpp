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
typedef tuple<int,int,int> TP ;
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

string S, T;
int n, m;
int dp[202][202][202];
TP pre[202][202][202];

int rec(int s, int t, int u){
    if(s == n && t == m && u == 0) return dp[s][t][u] = 0;
    if(dp[s][t][u] != 1e9) return dp[s][t][u];
    if(s == n && t == m && u > 0){
        if(dp[n][m][u] > rec(n,m,u-1) + 1){
            dp[n][m][u] = rec(n,m,u-1) + 1;
            pre[n][m][u] = {n,m,u-1};
        }
        return dp[n][m][u];
    }
    // {
    if(S[s] == T[t] && S[s] == '('){
        if(dp[s][t][u] > rec(s+1,t+1,u+1)+1){
            dp[s][t][u] = rec(s+1,t+1,u+1)+1;
            pre[s][t][u] = {s+1,t+1,u+1};
        }
    }
    if(S[s] != T[t] && S[s] == '('){
        if(dp[s][t][u] > rec(s+1,t,u+1)+1){
            dp[s][t][u] = rec(s+1,t,u+1)+1;
            pre[s][t][u] = {s+1,t,u+1};
        }
    }
    if(S[s] != T[t] && T[t] == '('){
        if(dp[s][t][u] > rec(s,t+1,u+1)+1){
            dp[s][t][u] = rec(s,t+1,u+1)+1;
            pre[s][t][u] = {s,t+1,u+1};
        }
    }
    if(S[s] != '(' && T[t] != '(' && u == 0){
        if(dp[s][t][u] > rec(s,t,u+1)+1){
            dp[s][t][u] = rec(s,t,u+1)+1;
            pre[s][t][u] = {s,t,u+1};
        }
    }
    // }
    if(S[s] == T[t] && S[s] == ')' && u > 0){
        if(dp[s][t][u] > rec(s+1,t+1,u-1)+1){
            dp[s][t][u] = rec(s+1,t+1,u-1)+1;
            pre[s][t][u] = {s+1,t+1,u-1};
        }
    }
    if(S[s] != T[t] && S[s] == ')' && u > 0){
        if(dp[s][t][u] > rec(s+1,t,u-1)+1){
            dp[s][t][u] = rec(s+1,t,u-1)+1;
            pre[s][t][u] = {s+1,t,u-1};
        }
    }
    if(S[s] != T[t] && T[t] == ')' && u > 0){
        if(dp[s][t][u] > rec(s,t+1,u-1)+1){
            dp[s][t][u] = rec(s,t+1,u-1)+1;
            pre[s][t][u] = {s,t+1,u-1};
        }
    }
    return dp[s][t][u];
}

void solve(){
    cin >> S >> T;
    n = S.size();
    m = T.size();
    S += 'x';
    T += 'x';
    rep(i,n+1) rep(j,m+1) rep(k,202) dp[i][j][k] = 1e9;
    rec(0,0,0);
    int bs = 0, bt = 0, bu = 0;
    string res = "";
    while(bs != n || bt != m || bu != 0){
        auto[s,t,u] = pre[bs][bt][bu];
        if(u > bu) res += '(';
        else res += ')';
        bs = s;
        bt = t;
        bu = u;
    }
    cout << res << endl;
}

int main(){
    // fast_input_output
    solve();
}