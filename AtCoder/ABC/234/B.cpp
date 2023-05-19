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

int n ;
ld X[1010] , Y[1010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    ld res = 0 ;
    rep(i,n){
        ld dist = 0 ;
        rep(j,n){
            dist = (X[j] - X[i]) * (X[j] - X[i]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) ;
            dist = sqrt(dist) ;
            chmax(res,dist) ;
        }
    }
    cout << fixed << setprecision(15) << res << endl ;
}