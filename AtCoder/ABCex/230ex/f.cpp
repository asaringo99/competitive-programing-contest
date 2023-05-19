#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n ;
ll A[202020] , S[202020] ;
ll dp[202020] , dps[202020] ;
int prevv[202020] ;
map<ll,vector<int>> B ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] ;
    rrep(i,1,n) B[S[i]].push_back(i) ;
    for(auto it : B){
        int id = it.second[0] ;
        prevv[id] = -1 ;
        int m = it.second.size() ;
        rrep(i,1,m) prevv[it.second[i]] = it.second[i-1] ;
    }
    dp[0] = 1 ;
    dps[0] = 1 ;
    rrep(i,1,n){
        int id = prevv[i] ;
        dp[i] += dps[i-1] ;
        if(id != -1) dp[i] -= dps[id-1] ;
        (dp[i] += mod) %= mod ;
        dps[i] = (dps[i-1] + dp[i]) % mod ;
        (dps[i] += mod) %= mod ;
    }
    ll res = 0 ;
    rep(i,n) (res += dp[i]) %= mod ;
    cout << res << endl ;
}