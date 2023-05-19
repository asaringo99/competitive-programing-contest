#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
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

int n , m , k ;
vector<int> G[1010] ;
int A[101] ;

int d[1010][1010] ;
int prevv[1010][1010] ;
map<P,int> mp ;
vector<int> X ;
unordered_map<int,ll> dp[1010] ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

void bfs(int s , int t){
    rep(i,n) d[s][i] = 1e8 ;
    d[s][s] = 0 ;
    prevv[s][s] = -1 ;
    queue<int> que ;
    que.push(s) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[s][u] > d[s][v] + 1){
                d[s][u] = d[s][v] + 1 ;
                prevv[s][u] = v ;
                que.push(u) ;
            }
        }
    }
    int v = t ;
    while(prevv[s][v] != -1){
        int a = min(prevv[s][v],v) ;
        int b = max(prevv[s][v],v) ;
        mp[P(a,b)]++ ;
        v = prevv[s][v] ;
    }
}

int main(){
    fast_input_output
    cin >> n >> m >> k ;
    rep(i,m) cin >> A[i] , A[i]-- ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    rep(i,m-1) bfs(A[i],A[i+1]) ;
    int count = 0 ;
    for(auto it : mp){
        count++ ;
        X.push_back(it.second) ;
    }

    ll res = powmod(2,n-1-count) ;
    dp[0][0] = 1 ;
    int r = X.size() ;
    rep(i,r){
        for(auto it : dp[i]){
            ll dpval = dp[i][it.first] ;
            (dp[i+1][it.first + X[i]] += dpval) %= mod ;
            (dp[i+1][it.first - X[i]] += dpval) %= mod ;
        }
    }
    (res *= dp[r][k]) %= mod ;
    cout << res << endl ;
}