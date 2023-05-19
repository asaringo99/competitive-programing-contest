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

int n , k ;
ll A[202020] , B[202020] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    ll a = A[0] , b = B[0] ;
    bool oka = true , okb = true ;
    bool ok = true ;
    rrep(i,1,n){
        bool ok_a = false , ok_b = false ;
        if(oka){
            if(abs(A[i] - A[i-1]) <= k) ok_a = true ;
            if(abs(B[i] - A[i-1]) <= k) ok_b = true ;
        }
        if(okb){
            if(abs(A[i] - B[i-1]) <= k) ok_a = true ;
            if(abs(B[i] - B[i-1]) <= k) ok_b = true ;
        }
        oka = ok_a ;
        okb = ok_b ;
        if(!oka && !okb) ok = false ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}