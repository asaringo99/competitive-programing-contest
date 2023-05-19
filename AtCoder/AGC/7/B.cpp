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
ll p[20202] ;
ll A[20202] , B[20202] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> p[i] , p[i]-- ;
    ll val = 1 ;
    rep(i,n){
        A[i] = val ;
        B[n-1-i] = val ;
        val += n ;
    }
    int cnt = 0 ;
    rep(i,n){
        int k = p[i] ;
        A[k] += cnt ;
        B[k] += cnt ;
        cnt++ ;
    }
    rep(i,n) cout << A[i] << " " ; cout << endl ;
    rep(i,n) cout << B[i] << " " ; cout << endl ;
}