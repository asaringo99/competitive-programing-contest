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

int k ;
ll A[101010] ;

int main(){
    cin >> k ;
    rep(i,k) cin >> A[i] ;
    ll a = 2 , b = 2 ;
    for(int i = k - 1 ; i >= 0 ; i--){
        ll x = a / A[i] , y = b / A[i] ;
        if(!(a <= y * A[i] && y * A[i] <= b)){
            cout << -1 << endl ;
            return 0 ;
        }
        if(a % A[i] != 0) x++ ; y++ ;
        a = x * A[i] ;
        b = y * A[i] - 1 ;
    }
    cout << a << " " << b << endl ;
}