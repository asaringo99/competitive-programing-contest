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
ll A[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    if(n % 2 == 1){
        if(n >= 2) cout << 1 << endl ;
        if(n == 1) cout << A[0] << endl ;
        return 0 ;
    }
    if(n == 2){
        cout << A[0] * A[1] << endl ;
        return 0 ;
    }
    sort(A,A+n) ;
    ll res = min(A[0]*A[1],A[2]) ;
    cout << res << endl ;
}