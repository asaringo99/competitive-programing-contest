#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<double,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define dist(xi,yi,xj,yj) sqrt( (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) )

struct edge{
    int to ;
    double cost ;
};

int n ;
double X[1010] , Y[1010] , T[1010] , R[1010] ;
vector<edge> G[1010] ;
double d[1010] ;

void djikstra(){
    rep(i,n) d[i] = 1e18 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] >> T[i] >> R[i] ;
    rep(i,n) rep(j,n){
        double xi = X[i] , yi = Y[i] , xj = X[j] , yj = Y[j] ;
        double ti = T[i] , rj = R[j] ;
        G[i].push_back(edge{j,dist(xi,yi,xj,yj) / min(ti,rj)}) ;
    }
    djikstra() ;
    double res = 0 ;
    sort(d,d+n) ;
    rep(i,n-1) res = max(res,d[n-1-i]+i) ;
    cout << fixed << setprecision(15) << res << endl ;
}