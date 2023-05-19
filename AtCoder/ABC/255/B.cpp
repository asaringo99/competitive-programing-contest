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

int n , k ;
int A[1010] ;
ld X[1010] , Y[1010] , L[1010] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,k) cin >> A[i] ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    ld res = 0 ;
    rep(i,n){
        L[i] = 1e18 ;
        rep(j,k){
            int p = A[j] ;
            p-- ;
            ld dist = (X[p] - X[i]) * (X[p] - X[i]) + (Y[p] - Y[i]) * (Y[p] - Y[i]) ;
            chmin(L[i],dist) ;
        }
        chmax(res,L[i]) ;
    }
    cout << fixed << setprecision(25) << sqrt(res) << endl ;
}