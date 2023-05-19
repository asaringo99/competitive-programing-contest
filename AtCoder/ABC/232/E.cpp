#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

ll H , W , k;
ll X1 , Y1 , X2 , Y2 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

ll A[1010101] , B[1010101] , C[1010101] , D[1010101] ;

int main(){
    cin >> H >> W >> k ;
    cin >> X1 >> Y1 >> X2 >> Y2 ;
    A[1] = 1 ;
    B[1] = 1 ;
    C[1] = 0 ;
    D[1] = 0 ;
    rrep(i,2,k+1){
        D[i] = ((H - 1) * A[i-1] % mod + (W - 1) * B[i-1] % mod) % mod ;
        A[i] = ((H - 2) * A[i-1] % mod + (W - 1) * C[i-1] % mod + D[i-1] % mod) % mod ;
        B[i] = ((W - 2) * B[i-1] % mod + (H - 1) * C[i-1] % mod + D[i-1] % mod) % mod ;
        C[i] = ((H - 2) * C[i-1] % mod + (W - 2) * C[i-1] % mod + A[i-1] + B[i-1] % mod) % mod ;
        // cout << A[i] << " " << B[i] << " " << C[i] << " " << D[i] << endl;
    }
    if(X1 == X2 && Y1 == Y2) cout << D[k] << endl ;
    else if(X1 == X2) cout << B[k] << endl ;
    else if(Y1 == Y2) cout << A[k] << endl ;
    else cout << C[k] << endl ;
}