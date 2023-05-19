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

const int mod = 1000000007 ;

ll n , m ;

int main(){
    // fast_input_output
    cin >> n >> m ;
    vector<P> vec ;
    for(ll i = 2 ; i * i <= m ; i++){
        if(m % i != 0) continue;
        int ex = 0 ;
        while(m % i == 0){
            ex++ ;
            m /= i ;
        }
        vec.push_back(P(i,ex)) ;
    }
    if(m != 1) vec.push_back(P(m,1)) ;
    int a = vec.size() ;
    ll res = 1 ;
    rep(p,a){
        auto[val,ex] = vec[p];
        vector<vector<ll>> dp(n,vector<ll>(ex+1,0)) ;
        rep(i,ex+1) dp[0][i] = 1 ;
        rep(i,n-1) rep(j,ex+1){
            rep(k,ex+1){
                if(j + k > ex) break;
                (dp[i+1][k] += dp[i][j]) %= mod ;
            }
        }
        ll sum = 0 ;
        rep(i,ex+1) (sum += dp[n-1][i]) %= mod ;
        (res *= sum) %= mod ;
    }
    cout << res << endl ;
}