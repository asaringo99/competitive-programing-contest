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

int H , W ;
int A[202020] , B[202020] ;
int res[202020] , ans[202020] ;

int main(){
    cin >> H >> W ;
    rep(i,H) cin >> A[i] >> B[i] , A[i]-- ;
    int x = 0 , y = 0 , d = 0 ;
    rep(i,H+2) res[i] = -1 ;
    rep(i,H){
        int a = A[i] , b = B[i] ;
        if(a <= y && y < b){
            d += b - y ;
            y = b ;
        }
        if(y == W) break ;
        x++ ;
        res[x] = x + d ;
    }
    x = 0 , y = B[0] , d = 0 ;
    rep(i,H+2) ans[i] = -1 ;
    rep(i,H){
        int a = A[i] , b = B[i] ;
        if(a <= y && y < b){
            d += b - y ;
            y = b ;
        }
        if(y == W) break ;
        x++ ;
        ans[x] = x + d ;
    }
    rrep(i,1,H+1){
        if(ans[i] > 0 && res[i] > 0) cout << min(ans[i],res[i]) << endl ;
        else if(ans[i] > 0) cout << ans[i] << endl ;
        else if(res[i] > 0) cout << res[i] << endl ;
        else cout << -1 << endl ;
    }
}