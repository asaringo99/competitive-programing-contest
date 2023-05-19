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
char C[1010][1010] ;
int S[1010][1010] ;
int A[1010][1010] ;
bool used[1010][1010] ;

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) {
        cin >> C[i][j] ;
        if(C[i][j] == '.') S[i][j] = 0 ;
        else S[i][j] = C[i][j] - '0' ;
    }
    queue<P> que , Q ;
    rrep(i,1,H-1) rrep(j,1,W-1) {
        if(S[i][j] > 0) {
            rrep(x,-1,2) rrep(y,-1,2) if(S[i+x][j+y] == 0) A[i][j]++ ;
            if(A[i][j] >= S[i][j]){
                que.push(P(i,j)) ;
                used[i][j] = true ;
            }
        }
    }
    int res = 0 ;
    while(!que.empty()){
        while(!que.empty()){
            auto [x,y] = que.front() ; que.pop() ;
            rrep(dx,-1,2) rrep(dy,-1,2) {
                int nx = x + dx , ny = y + dy ;
                if(S[nx][ny] != 0 && !used[nx][ny]) {
                    A[nx][ny]++ ;
                    if(A[nx][ny] >= S[nx][ny]){
                        Q.push(P(nx,ny)) ;
                        used[nx][ny] = true ;
                    }
                }
            }
        }
        while(!Q.empty()){
            que.push(Q.front()) ; Q.pop() ;
        }
        res++ ;
    }
    cout << res << endl ;
}