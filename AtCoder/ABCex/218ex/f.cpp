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

int n , m ;

set<P> st ;
vector<int> G[202020] ;
ll d[202020] ;
int prevv[202020] ;
P edge[202020] ;

void djikstra(int nv , int nu){
    rep(i,n) d[i] = 1e16 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(min(u,v) == min(nu,nv) && max(u,v) == max(nu,nv)) continue;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                que.push(P(d[u],u)) ;
                prevv[u] = v ;
            }
        }
    }
    if(nv == -1 && nu == -1){
        int v = n - 1 ;
        while(v != 0){
            int u = v ;
            v = prevv[v] ;
            st.insert(P(v,u)) ;
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        ll v , u ;
        cin >> v >> u ;
        v-- ; u-- ;
        G[v].push_back(u) ;
        edge[i] = P(v,u) ;
    }
    djikstra(-1,-1) ;
    ll cost = d[n-1] ;
    if(cost == 1e16){
        rep(i,m) cout << -1 << endl ;
        return 0 ;
    }
    rep(i,m){
        auto [v,u] = edge[i] ;
        if(st.count(P(v,u)) == 1){
            djikstra(v,u) ;
            ll res = d[n-1] ;
            if(res == 1e16) res = -1 ;
            cout << res << endl ;
        }
        else cout << cost << endl ;
    }
}