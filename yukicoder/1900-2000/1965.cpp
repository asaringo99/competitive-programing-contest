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

int n ;
ll A[202020] , B[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    ll p = A[0] + B[0] ;
    ll m = A[0] - B[0] ;
    ll res = 0 , count = 1 ;
    rrep(i,1,n){
        ll np = A[i] + B[i] ;
        ll nm = A[i] - B[i] ;
        if(np > p && nm > m) res += count++ ;
        else count = 1 ;
        p = np ;
        m = nm ;
    }
    cout << res << endl ;
}