#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , q ;
ll X[60] , Y[60] , Z[60] , W[60] ;

int main(){
    cin >> n >> q ;
    rep(i,q) cin >> X[i] >> Y[i] >> Z[i] >> W[i] ;
    rep(i,q) X[i]-- , Y[i]-- , Z[i]-- ;
    ll res = 1 ;
    for(int i = 0 ; i < 60 ; i++){
        ll cnt = 0 ;
        for(int S = 0 ; S < (1 << n) ; S++){
            bool bit[20] ;
            memset(bit,0,sizeof(bit)) ;
            for(int k = 0 ; k < n ; k++) if(S >> k & 1) bit[k] = true ;
            bool ok = true ;
            for(int k = 0 ; k < q ; k++){
                bool x = bit[X[k]] , y = bit[Y[k]] , z = bit[Z[k]] ;
                bool w = W[k] >> i & 1 ;
                bool val = x | y | z ;
                if(w ^ val == 1) ok = false ;
            }
            if(ok) cnt++ ;
        }
        (res *= cnt) %= mod ;
    }
    cout << res << endl ;
}