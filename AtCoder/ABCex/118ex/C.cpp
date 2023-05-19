#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int match[] = {0,2,5,5,4,5,6,3,7,6} ;

int n , m ;
int A[10] ;
P dp[10101] ;
int pre[10101] ;

int main(){
    cin >> n >> m ;
    rep(i,m) cin >> A[i] ;
    rep(i,n+1) dp[i] = P(-1,-1) ;
    dp[0] = P(0,0) ;
    rep(i,n){
        if(dp[i].first == -1) continue ;
        rep(j,m){
            int v = match[A[j]] ;
            int x = dp[i].first , dig = dp[i].second ;
            if(dp[i+v] < P(x+1,A[j])){
                dp[i+v] =P(x+1,A[j]) ;
                pre[i+v] = i ;
            }
        }
    }
    string S = "" ;
    int v = n ;
    while(v != 0){
        S += to_string(dp[v].second) ;
        v = pre[v] ;
    }
    cout << S << endl ;
}