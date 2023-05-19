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

int n , k ;
vector<int> G[11] ;
ll dp[2020] ;

int main(){
    cin >> n >> k ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        b-- ;
        G[b].push_back(a) ;
    }
    rep(i,10){
        sort(G[i].begin(),G[i].end(),greater<ll>()) ;
        ll t = 0 ;
        rep(j,G[i].size()){
            G[i][j] += t ;
            t = G[i][j] ;
        }
        ll s = 0 ;
        rep(j,G[i].size()){
            G[i][j] += s ;
            ll mag = 2 * (j + 1) ;
            s += mag ;
        }
    }
    rep(i,10){
        for(int j = k - 1 ; j >= 0 ; j--){
            rep(s,G[i].size()){
                if(j + s + 1 > k) continue ;
                chmax(dp[j+s+1],dp[j]+G[i][s]) ;
            }
        }
    }
    cout << dp[k] << endl ;
}