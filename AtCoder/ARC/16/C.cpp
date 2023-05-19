#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
int idol[11][20] , C[20] ;
double cost[11] , p[11][20] ;
double dp[1 << 15] ;

double rec(int S){
    if(S == (1 << n) - 1) return dp[S] = 0 ;
    if(dp[S] >= 0) return dp[S] ;
    double res = 1e50 ;
    for(int i = 0 ; i < m ; i++){
        double sum = 0 ;
        for(int j = 0 ; j < C[i] ; j++) if(S >> idol[i][j] & 1) sum += p[i][j] ;
        if(abs(sum - 1) < 1e-10) continue ;
        double val = cost[i] ;
        for(int j = 0 ; j < C[i] ; j++){
            if(S >> idol[i][j] & 1) continue ;
            val += rec(S | 1 << idol[i][j]) * p[i][j] ;
        }
        val /= 1 - sum ;
        res = min(res,val) ;
    }
    return dp[S] = res ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        cin >> C[i] >> cost[i] ;
        rep(j,C[i]){
            cin >> idol[i][j] >> p[i][j] ;
            idol[i][j]-- ;
            p[i][j] /= 100.0 ;
        }
    }
    rep(i,(1<<n)+20) dp[i] = -1 ;
    cout << fixed << setprecision(10) << rec(0) << endl ;
}