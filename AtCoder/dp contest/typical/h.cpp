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

int n , w , c ;
int dp[55][10101] , dp2[55][10101] ;
vector<P> X[55] ;

int main(){
    cin >> n >> w >> c ;
    rep(i,n){
        ll a , b , c ;
        cin >> a >> b >> c ;
        X[c-1].push_back(P(a,b)) ;
    }
    rep(i,c+1) rep(j,w+1) dp[i][j] = -1 ;
    dp[0][0] = 0 ;
    rep(i,50){
        vector<P> item = X[i] ;
        int m = item.size() ;
        for(int k = c ; k > 0 ; k--) rep(l,w+1){
            dp2[k][l] = dp[k-1][l] ;
        }
        rep(j,m){
            int x = item[j].first , y = item[j].second ;
            rrep(k,1,c+1) for(int l = w ; l >= 0 ; l--) if(dp2[k][l] != -1){
                if(l + x > w) continue ;
                chmax(dp2[k][l+x],dp2[k][l]+y) ;
            }
        }
        rep(j,c+1) rep(l,w+1) chmax(dp[j][l],dp2[j][l]) ;
    }
    int res = 0 ;
    rep(i,c+1) rep(j,w+1) chmax(res,dp[i][j]) ;
    cout << res << endl ;
}