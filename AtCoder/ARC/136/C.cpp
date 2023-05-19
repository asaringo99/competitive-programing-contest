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
ll A[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll val = max(A[0],A[n-1]) ;
    ll maxval = 0 , minval = 1e10 , id = -1 ;
    if(val == A[n-1]){
        for(int i = n - 2 ; i >= 0 ; i--){
            chmin(minval,A[i]) ;
            if(maxval < A[i]){
                id = i ;
                maxval = A[i] ;
            }
        }
    }
}