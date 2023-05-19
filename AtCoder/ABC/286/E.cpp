#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

// int n, q;

// P dp[303][303];
// ll A[303];
// ll d[303][303];

struct edge{
    int to ;
    ll cost ;
};

int n , q ;

ll A[303];
vector<edge> G[303] ;
P d[303][303] ;
bool is_go[303][303];

void warshall_floyd(){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) {
                // if(!is_go[i][j]) continue;
                ll sec = d[i][k].second + d[k][j].second;
                ll fir = d[i][k].first + d[k][j].first;
                P res = {fir, sec};
                d[i][j] = min(d[i][j] , res) ;
            }
}

// P djikstra(int s, int t){
//     rep(i,n) d[i] = {1e16,1e16} ;
//     d[s] = {0,A[s]} ;
//     priority_queue<TP,vector<TP>,greater<TP>> que ;
//     que.push({0,-A[s],s}) ;
//     while(!que.empty()){
//         auto[dist,val,v] =  que.top() ; que.pop() ;
//         P dis = {dist, val};
//         if(d[v] < dis) continue;
//         for(int i = 0 ; i < G[v].size() ; i++){
//             edge e = G[v][i] ;
//             P con = {dist + e.cost, val - A[e.to]};
//             if(d[e.to] > con){
//                 d[e.to] = {dist + e.cost, val - A[e.to]} ;
//                 que.push({dist + e.cost, val - A[e.to], e.to}) ;
//             }
//         }
//     }
//     return d[t];
// }

int main(){
    fast_io
    cin >> n ;
    rep(i,n) cin >> A[i];
    rep(i,n){
        string S;
        cin >> S;
        rep(j,n) {
            if(S[j] == 'Y') {
                is_go[i][j] = true;
                d[i][j] = {1,-A[j]};
            }
            else d[i][j] = {1e16, 1e16};
        }
    }
    warshall_floyd();
    cin >> q;
    rep(i,q){
        int u, v;
        cin >> u >> v;
        u--; v--;
        P res = d[u][v];
        if(res.first == 1e16) pt("Impossible");
        else cout << res.first << " " << -res.second + A[u] << endl;
    }
}