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
ll A[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    if(n == 1 || n == 2){
        cout << 0 << endl ;
        return 0 ;
    }
    ll res = 1e18 ;
    int mag = A[0] - A[1] ;
    rrep(a,A[0]-1,A[0]+2) rrep(b,A[1]-1,A[1]+2){
        ll mag = b - a ;
        ll x = b ;
        ll sum = abs(a-A[0]) + abs(b-A[1]) ;
        bool ok = true ;
        rrep(i,2,n){
            ll v = A[i] ;
            x += mag ;
            if(abs(v - x) > 1) ok = false ;
            sum += abs(v-x) ;
        }
        if(ok) chmin(res,sum) ;
    }
    if(res == 1e18) res = -1 ;
    cout << res << endl ;
} 