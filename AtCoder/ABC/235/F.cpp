#include <bits/stdc++.h>
using namespace std ;
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
#define endl "\n"

const int mod = 998244353 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int n , m ;
string S ;
vector<int> digit ;
ll dp[10101][2][(1<<10)+10] ;
bool used[10101][2][(1<<10)+10] ;
set<int> st ;

int main(){
    cin >> S >> m ;
    n = S.size() ;
    rep(i,n) digit.push_back(S[i] - '0') ;

    rep(i,m){
        int c ;
        cin >> c ;
        st.insert(c) ;
    }
    int T = 0 ;
    rep(i,n){
        int d = digit[i] ;
        // smaller: 0
        {
            (dp[i+1][0][T | 1 << d] += dp[i][0][T] * 10 + d) %= mod ;
            rep(j,d){
                (dp[i+1][1][T | 1 << j] += dp[i][0][T] * 10 + j) %= mod ;
                if(j != 0) used[i+1][1][T | 1 << j] = true ;
                // cout << (T | 1 << j) << " " << dp[i+1][1][T | 1 << j] << endl ;
            }
            T = T | 1 << d ;
        }
        // rep(j,10){
        //     used[i][1][1<<j] = true ;
        //     (dp[i][1][1<<j] += j) %= mod ;
        // }
        // smaller: 1
        {
            rep(S,1<<10){
                if(!used[i][1][S]) continue ;
                rep(j,10){
                    (dp[i+1][1][S | 1 << j] += dp[i][1][S] * 10 + j) %= mod ;
                    used[i+1][1][S | 1 << j] = true ;
                }
                // cout << i << " " << S << " " << dp[i][1][S] << endl ;
            }
        }
    }
    ll res = 0 ;
    rep(S,1<<10){
        bool ok = true ;
        for(int u : st){
            if(!(S >> u & 1)) ok = false ;
        }
        if(ok) {
            (res += dp[n][0][S] + dp[n][1][S]) %= mod ;
            // cout << S << " " << dp[n][0][S] << " " << dp[n][1][S] << endl ;
        }
    }
    cout << res << endl ;
}