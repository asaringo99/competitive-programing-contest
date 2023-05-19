#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

ll n , m , k ;
vector<int> G[1010] ;
ll d[1010] , e[1010] ;
int A[101] ;
int pre[1010] ;
map<P,int> mp ;
unordered_map<ll,ll> dp[1010] ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

void djikstra(int s , int t){
    rep(i,n) d[i] = 1e16 ;
    rep(i,n) pre[i] = -1 ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                pre[u] = v ;
                que.push(P(d[u],u)) ;
            }
        }
    }
    int v = t ;
    while(pre[v] != -1){
        int u = pre[v] ;
        mp[P(min(v,u),max(v,u))]++ ;
        v = u ;
    }
}

int main(){
    cin >> n >> m >> k ;
    rep(i,m) cin >> A[i] , A[i]-- ;
    rep(i,n-1){
        int v , u ;
        cin >> v >> u ;
        v-- ; u-- ;
        G[v].push_back(u) ;
        G[u].push_back(v) ;
    }
    rep(i,m-1){
        djikstra(A[i],A[i+1]) ;
    }
    // for(auto it : mp) cout << it.second << " " ;
    // cout << endl ;
    int id = 0 ;
    for(auto it : mp) {
        e[id] = it.second ;
        id++ ;
    }
    ll res = powmod(2,n-1-id) ;
    dp[0][0] = 1 ;
    rep(i,id){
        for(auto it : dp[i]){
            // cout << it.first << " " ;
            (dp[i+1][it.first+e[i]] += it.second) %= mod ;
            (dp[i+1][it.first-e[i]] += it.second) %= mod ;
        }
        // cout << endl ;
    }
    cout << dp[id][k] * res % mod << endl ;
}