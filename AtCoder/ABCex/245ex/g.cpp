#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

struct edge {
    int to ;
    ll cost ;
};

int n , m , k , L ;
int A[101010] , B[101010] ;
P d[101010][2] ;
vector<edge> G[101010] ;

void djikstra(){
    rep(i,n) {
        d[i][0] = P(1e16,i) ;
        d[i][1] = P(1e16,i) ;
    }
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    rep(i,L){
        d[B[i]][0] = P(0,A[B[i]]) ;
        que.push({0,B[i],A[B[i]]}) ;
    }
    while(!que.empty()){
        auto [dist,v,from] = que.top() ; que.pop() ;
        if(dist > d[v][1].first) continue;
        if(d[v][0].second == from && dist > d[v][0].first) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to][1].first < dist + e.cost) continue ;
            if(d[e.to][0].second == from){
                if(d[e.to][0].first > dist + e.cost){
                    d[e.to][0] = P(dist+e.cost,from) ;
                    que.push({dist+e.cost,e.to,from}) ;
                }
            }
            else{
                if(d[e.to][1].first > dist + e.cost){
                    d[e.to][1] = P(dist+e.cost,from) ;
                    que.push({dist+e.cost,e.to,from}) ;
                }
                if(d[e.to][1].first < d[e.to][0].first) swap(d[e.to][0],d[e.to][1]) ;
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m >> k >> L ;
    rep(i,n) cin >> A[i] , A[i]-- ;
    rep(i,L) cin >> B[i] , B[i]-- ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    djikstra() ;
    rep(i,n){
        ll res = 1e16 ;
        if(d[i][0].second == A[i]){
            if(d[i][1].first != 1e16) res = d[i][1].first ;
        }
        else res = d[i][0].first ;
        res = res == 1e16 ? -1 : res ;
        cout << res << " " ;
    }
    cout << endl ;
}

