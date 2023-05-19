#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ld p ;

int main(){
    cin >> n >> p ;
    if(n >= 200){
        cout << 1 << endl ;
        return 0 ;
    }
    p = 1 - p ;
    ld res = 1 ;
    rep(i,n) res *= p ;
    res = 1 - res ;
    cout << fixed << setprecision(15) << res << endl ;
}