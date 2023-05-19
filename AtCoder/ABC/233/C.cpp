#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , x ;
ll L[101010] ;
vector<ll> A[101010] ;
unordered_map<ll,ll> dp[101010] ;

int main(){
    cin >> n >> x ;
    rep(i,n){
        int l ;
        cin >> l ;
        L[i] = l ;
        rep(j,l){
            ll a ;
            cin >> a ;
            A[i].push_back(a) ;
        }
    }
    dp[0][1] = 1 ;
    rep(i,n){
        for(auto it : dp[i]){
            ll y = it.first ;
            rep(j,L[i]){
                if(A[i][j] > 1e18 / y) continue ;
                dp[i+1][y*A[i][j]] += dp[i][y] ;
            }
        }
    }
    cout << dp[n][x] << endl ;
}