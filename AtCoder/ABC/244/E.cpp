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

const int mod = 998244353 ;

int n , m , k , s , t , x ;
vector<int> G[2020] ;
ll dp[2020][2020][2] ;


int main(){
    cin >> n >> m >> k >> s >> t >> x ;
    s-- ;
    t-- ;
    x-- ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dp[s][0][0] = 1 ;
    queue<P> que ;
    que.push(P(s,0)) ;
    rep(i,k){
        rep(v,n) rep(cnt,2) {
            for(int j = 0 ; j < G[v].size() ; j++){
                int u = G[v][j] ;
                if(u == x) (dp[u][i+1][abs(cnt-1)] += dp[v][i][cnt]) %= mod ;
                else (dp[u][i+1][cnt] += dp[v][i][cnt]) %= mod ;
            }
        }
    }
    cout << dp[t][k][0] << endl ;
}