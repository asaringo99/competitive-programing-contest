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

int H , W , n ;
int  C[101] ;
int A[202][202] ;
int S[202][202] ;

const int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;

int main(){
    cin >> H >> W >> n ;
    rep(i,H) rep(j,W) cin >> A[i][j] , A[i][j]-- ;
    rep(i,n) cin >> C[i] , C[i]-- ;
    rep(i,H) rep(j,W) {
        S[i][j] = -1 ;
    }
    bool ok = true ;
    rep(c,n){
        rep(x,H) rep(y,W){
            if(A[x][y] == c){
                S[x][y] = C[c] ;
                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + dx[i] , ny = y + dy[i] ;
                    if(0 > nx || nx >= H || 0 > ny || ny >= W) continue ;
                    if(S[nx][ny] == C[c] && A[nx][ny] != c) ok = false ;
                }
            }
        }
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl;
}