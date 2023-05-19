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

int n , m ;
bool A[202020] , B[202020] ;

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m) {
        int a ;
        cin >> a ;
        A[a] = true ;
    }
    int res = 0 ;
    for(int i = n ; i >= 1 ; i--){
        for(ll x = 1 ; x * x <= i ; x++){
            if(i % x == 0){
                B[x] = B[x] ? false : true ; 
                if(x * x != i) B[i/x] = B[i/x] ? false : true ;  ;
            }
        }
    }
    for(int i = n ; i >= 1 ; i--){
        if(A[i] != B[i]) {
            for(ll x = 1 ; x * x <= i ; x++){
                if(i % x == 0){
                    B[x] = B[x] ? false : true ; 
                    if(x * x != i) B[i/x] = B[i/x] ? false : true ;  ;
                }
            }
            res++ ;
        }
    }
    cout << res << endl ;
}