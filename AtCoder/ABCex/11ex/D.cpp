#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

double comb[1010][1010] ;

void pascal(){
    comb[0][0] = 1 ;
    rep(i,1005) rep(j,1005){
        comb[i+1][j] += comb[i][j] / 2 ;
        comb[i+1][j+1] += comb[i][j] / 2 ;
    }
}

ll n , d , x , y ;
unordered_map<ll,double> dp1[1010] ;
unordered_map<ll,double> dp2[1010] ;

int main(){
    pascal() ;
    cin >> n >> d >> x >> y ;
    dp1[0][0] = 1 ;
    rep(i,n){
        for(auto it : dp1[i]){
            dp1[i+1][it.first + d] += it.second / 2 ;
            dp1[i+1][it.first - d] += it.second / 2 ;
        }
    }
    dp2[0][0] = 1 ;
    rep(i,n){
        for(auto it : dp2[i]){
            dp2[i+1][it.first + d] += it.second / 2 ;
            dp2[i+1][it.first - d] += it.second / 2 ;
        }
    }
    double res = 0 ;
    rrep(i,0,n+1) res += dp1[i][x] * dp2[n-i][y] * comb[n][i] ;
    cout << fixed << setprecision(15) << res << endl ;
}