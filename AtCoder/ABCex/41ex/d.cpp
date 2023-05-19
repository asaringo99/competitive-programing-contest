#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
ll dp[1 << 20] ;
vector<int> G[1010] ;

int main(){
    cin >> n >> m ;
    rep(i,m) {
        int x , y ;
        cin >> x >> y ;
        x-- ; y-- ;
        G[x].push_back(y) ;
    }
    dp[0] = 1 ;
    rep(S,1<<n){
        rep(i,n){
            if(S >> i & 1) continue ;
            bool ok = true ;
            for(int y : G[i]) if(S >> y & 1) ok = false ;
            if(ok) dp[S | 1 << i] += dp[S] ;
        }
    }
    cout << dp[(1 << n) - 1] << endl ;
}