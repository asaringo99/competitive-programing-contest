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

int next_[202][26];
ll n, k;
string S;
ll dp[202][202];

void f(){
    rep(i,26) next_[n+1][i] = n+1;
    for(int i = n ; i >= 0 ; i--){
        rep(j,26) next_[i][j] = next_[i+1][j];
        if(i > 0) next_[i][S[i-1]-'a'] = i;
    }
}

void solve(){
    cin >> n >> k >> S;
    f();
    dp[0][0] = 1;
    rep(i,n+1){
        rep(j,n){
            rep(x,26){
                int p = next_[i+1][x];
                dp[p][j+1] += dp[i][j];
                if(dp[p][j+1] >= k) dp[p][j+1] = k;
            }
        }
    }
    ll res = 0;
    for(int i = n ; i >= 0 ; i--){
        rep(j,n+1){
            if(k - dp[j][i] > 0){
                k -= dp[j][i];
                res += (n - i) * dp[j][i];
            }
            else{
                res += k * (n - i);
                k = 0;
            }
        }
    }
    if(k > 0){
        cout << -1 << endl;
    }
    else{
        cout << res << endl;
    }
}

int main(){
    fast_input_output
    solve();
}