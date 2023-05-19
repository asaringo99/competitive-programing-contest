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
int X[202020] ;
int A[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    int res = 0 ;
    rep(i,n){
        int a = A[i] ;
        X[a] = X[a-1] + 1 ;
        chmax(res,X[a]) ;
    }
    cout << n - res << endl ;
}