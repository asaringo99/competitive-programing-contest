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

int n , t ;
int A[1010][11] , C[11] ;

int main(){
    cin >> t >> n ;
    rep(i,t) rep(j,n) cin >> A[i][j] ;
    rep(i,t){
        rep(j,n){
            chmax(C[j],A[i][j]) ;
        }
        int sum = 0 ;
        rep(j,n){
            sum += C[j] ;
        }
        cout << sum << endl ;
    }
}