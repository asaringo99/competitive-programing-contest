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
char C[303][303] ;

int main(){
    cin >> n ;
    rep(i,n) rep(j,n) cin >> C[i][j] ;
    int res = 0 ;
    rep(i,n){
        bool ok = true ;
        rep(j,n){
            rep(k,n){
                if(C[(i+j)%n][k] != C[(i+k)%n][j]) ok = false ;
            }
        }
        if(ok) res += n ;
    }
    cout << res << endl ;
}