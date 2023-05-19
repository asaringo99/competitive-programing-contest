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

int h , w ;
ll W[404][404] , G[404][404] , B[404][404] ;
ll X[404][404] , Y[404][404] , Z[404][404] ;
int C[404][404] ;

int main(){
    cin >> h >> w ;
    rep(i,h) rep(j,w) cin >> C[i][j] ;
    ll res = 0 ;
    rep(k,w){
        rep(i,h){
            rrep(j,i+1,h){
                if((C[i][k] == 0 && C[j][k] == 1) || (C[i][k] == 1 && C[j][k] == 0)) res += Z[i][j] + B[i][j] + G[i][j] ;
                if((C[i][k] == 0 && C[j][k] == 2) || (C[i][k] == 2 && C[j][k] == 0)) res += Y[i][j] + G[i][j] + W[i][j] ;
                if((C[i][k] == 1 && C[j][k] == 2) || (C[i][k] == 2 && C[j][k] == 1)) res += X[i][j] + W[i][j] + B[i][j] ;
                if(C[i][k] == 0 && C[j][k] == 0) res += G[i][j] ;
                if(C[i][k] == 1 && C[j][k] == 1) res += B[i][j] ;
                if(C[i][k] == 2 && C[j][k] == 2) res += W[i][j] ;
            }
        }
        rep(i,h){
            rrep(j,i+1,h){
                if(C[i][k] == 0 && C[j][k] == 0) X[i][j]++ ;
                if(C[i][k] == 1 && C[j][k] == 1) Y[i][j]++ ;
                if(C[i][k] == 2 && C[j][k] == 2) Z[i][j]++ ;
            }
        }
        rep(i,h){
            rrep(j,i+1,h){
                if((C[i][k] == 0 && C[j][k] == 1) || (C[i][k] == 1 && C[j][k] == 0)) W[i][j]++ ;
                if((C[i][k] == 0 && C[j][k] == 2) || (C[i][k] == 2 && C[j][k] == 0)) B[i][j]++ ;
                if((C[i][k] == 1 && C[j][k] == 2) || (C[i][k] == 2 && C[j][k] == 1)) G[i][j]++ ;
            }
        }
    }
    cout << res << endl ;
}