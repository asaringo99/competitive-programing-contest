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

ll n , q , x ;
ll W[202020] , S[404040] ;
ll dp[60][202020] ;
ll res[202020] ;

void rec(){
    rep(i,50){
        rep(j,n){
            dp[i+1][j] = dp[i][dp[i][j]] ;
        }
    }
}

ll get(ll n){
    ll x = 0 , c = 0 ;
    while(n > 0){
        if(n & 1) x = dp[c][x] ;
        c++ ;
        n >>= 1 ;
    }
    return x ;
}

int main(){
    // fast_input_output
    cin >> n >> q >> x ;
    rep(i,n) cin >> W[i];
    rep(i,3*n) S[i+1] = S[i] + W[i%n] ;
    ll sum = S[n] ;
    rep(i,n){
        ll c = x % sum ;
        auto it = lower_bound(S,S+3*n+1,c+S[i]) ;
        int id = it - S ;
        id %= n ;
        dp[0][i] = id ;
    }
    rec() ;
    rep(i,q){
        ll k ;
        cin >> k ;
        k-- ;
        ll s = get(k) ;
        ll cnt = x / sum ;
        if(x % sum == 0){
            cout << cnt * n << endl ;
            continue;
        }
        ll nex = dp[0][s] ;
        if(nex <= s) nex += n ;
        cout << cnt * n + nex - s << endl ;
        // cout << s << " " << nex << endl ;
        // if(nex < s) cout << cnt + (n - s) + nex << endl ;
        // else cout << cnt + nex - s << endl ;
    }
}