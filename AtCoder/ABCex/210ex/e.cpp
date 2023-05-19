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

int n , m ;
P X[101010] ;

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m){
        ll a , c ;
        cin >> a >> c ;
        X[i] = P(c,a) ;
    }
    sort(X,X+m) ;
    ll g = n , res = 0 ;
    rep(i,m){
        auto [c,a] = X[i] ;
        ll k = g ;
        g = gcd(g,a) ;
        res += (k / g - 1) * g * c ;
        if(g == 1) break ;
    }
    if(g != 1) res = -1 ;
    cout << res << endl ;
}