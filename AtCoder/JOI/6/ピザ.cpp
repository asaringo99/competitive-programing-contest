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

int d , n , m ;
ll S[202020] ;

int main(){
    cin >> d >> n >> m ;
    rep(i,n-1) cin >> S[i+1] ;
    sort(S,S+n) ;
    rep(i,n) S[i + n] = S[i] + d ;
    ll res = 0 ;
    rep(i,m){
        ll a ;
        cin >> a ;
        auto it = upper_bound(S,S+2*n,a) ;
        ll x = *it ; it-- ;
        ll y = *it ;
        res += min(abs(x-a),abs(y-a)) ;
    }
    cout << res << endl ;
}