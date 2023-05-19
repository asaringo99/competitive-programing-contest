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

struct edge{
    int to ;
    ll cost ;
};

int n , m , k ;
bool A[3030] ;

vector<edge> G[3030] ;
ll d[3030] ;

void djikstra(){
    rep(i,n) d[i] = 1e16 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    rep(i,n){
        if(A[i]){
            d[i] = 0 ;
            que.push(P(0,i)) ;
        }
    }
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

TP X[101010] ;

int main(){
    cin >> n >> m >> k ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
        X[i] = TP{a,b,c} ;
    }
    rep(i,k){
        int a ;
        cin >> a ;
        a-- ;
        A[a] = true ;
    }
    djikstra() ;
    int res = 0 ;
    rep(i,m){
        auto[v,u,len] = X[i] ;
        if(len == 0) continue;
        int a = d[v] ;
        int b = d[u] ;
        int val = (b - a + len + 1) / 2 ;
        chmax(res,val + a) ;
    }
    cout << res << endl ;
}