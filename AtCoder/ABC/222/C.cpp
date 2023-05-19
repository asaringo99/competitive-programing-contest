#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
char A[202][202] ;
P g[202] ;

int main(){
    cin >> n >> m ;
    rep(i,2*n) rep(j,m) cin >> A[i][j] ;
    rep(i,2*n) g[i] = P(0,-i) ;
    rep(i,m) {
        // rep(j,2*n) cout << g[j].first << " " << g[j].second << "| " ;
        // cout << endl ;
        rep(j,2*n) {
            if(j % 2 == 1) continue ;
            if(A[-g[j].second][i] == A[-g[j+1].second][i]) continue ;
            else if(A[-g[j].second][i] == 'G' && A[-g[j+1].second][i] == 'C') g[j].first++ ;
            else if(A[-g[j].second][i] == 'C' && A[-g[j+1].second][i] == 'P') g[j].first++ ; 
            else if(A[-g[j].second][i] == 'P' && A[-g[j+1].second][i] == 'G') g[j].first++ ;
            else if(A[-g[j].second][i] == 'C' && A[-g[j+1].second][i] == 'G') g[j+1].first++ ;
            else if(A[-g[j].second][i] == 'P' && A[-g[j+1].second][i] == 'C') g[j+1].first++ ; 
            else if(A[-g[j].second][i] == 'G' && A[-g[j+1].second][i] == 'P') g[j+1].first++ ;
        }
        sort(g,g+2*n,greater<P>()) ;
    }
    rep(i,2*n){
        cout << abs(g[i].second) + 1 << endl ;
    }
}