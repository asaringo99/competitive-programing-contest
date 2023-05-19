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

int H , W , m ;
char S[202][202] , C[202][202] , D[202][202] ;
bool T[2][202] ;

int main(){
    fast_input_output
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    cin >> m ;
    rep(i,m){
        int t , n ;
        cin >> t >> n ;
        t-- ; n-- ;
        T[t][n] = true ;
    }
    for(int j = W - 2 ; j >= 0 ; j--){
        if(S[H-1][j] == S[H-1][j+1] && T[1][j]){
            rep(x,H) rep(y,j+1) S[x][y] = S[x][y] == '#' ? '.' : '#' ;
        }
    }
    for(int i = H - 2 ; i >= 0 ; i--){
        if(S[i][W-1] == S[i+1][W-1] && T[0][i]){
            rep(x,i+1) rep(y,W) S[x][y] = S[x][y] == '#' ? '.' : '#' ;
        }
    }
    rep(i,H) rep(j,W) C[i][j] = (i + j) % 2 == 0 ? '#' : '.' ;
    rep(i,H) rep(j,W) D[i][j] = (i + j) % 2 == 0 ? '.' : '#' ;
    bool ok1 = true , ok2 = true ;
    rep(i,H) rep(j,W) if(S[i][j] != C[i][j]) ok1 = false ;
    rep(i,H) rep(j,W) if(S[i][j] != D[i][j]) ok2 = false ;
    if(ok1 || ok2) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}