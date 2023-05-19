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

int H , W , n , sx , sy , gx , gy ;
map<int,vector<P>> X , Y ;
map<P,int> mp ;
vector<int> G[101010] ;
P C[101010] ;
map<P,int> d ;

void djikstra(int sx , int sy){
    d[P(sx,sy)] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,sx,sy}) ;
    while(!que.empty()){
        int dist , x , y ;
        tie(dist,x,y) = que.top() ; que.pop() ;
        if(d[P(x,y)] < dist) continue;

        auto it = upper_bound(X[x].begin(),X[x].end(),P(x,-1)) ;
        if(it != X[x].end()){
            P p = *it ;
            int nx = C[p.second].first , ny = C[p.second].second ;
            if(d[P(nx-1,ny)] > d[P(x,y)] + 1){
                d[P(nx-1,ny)] = d[P(x,y)] + 1 ;
                que.push({d[P(nx-1,ny)],nx-1,ny}) ;
            }
        }
        auto jt = lower_bound(X[x].begin(),X[x].end(),P(x,-1)) ;
        if(jt != X[x].end()){
            P p = *jt ;
            int nx = C[p.second].first , ny = C[p.second].second ;
            if(d[P(nx-1,ny)] > d[P(x,y)] + 1){
                d[P(nx-1,ny)] = d[P(x,y)] + 1 ;
                que.push({d[P(nx-1,ny)],nx-1,ny}) ;
            }
        }



    }
}

int main(){
    cin >> H >> W >> n >> sx >> sy >> gx >> gy ;
    X[sx].push_back(P(sy,0)) ;
    Y[sy].push_back(P(sx,0)) ;
    X[gx].push_back(P(gy,n+1)) ;
    Y[gy].push_back(P(gx,n+1)) ;
    rrep(i,1,n+1){
        int x , y ;
        cin >> x >> y ;
        X[x].push_back(P(y,i)) ;
        Y[y].push_back(P(x,i)) ;
        C[i] = P(x,y) ;
        mp[P(x,y)] = i ;
    }
    for(auto it : X){
        sort(X[it.first].begin(),X[it.first].end()) ;
    }
    for(auto it : Y){
        sort(Y[it.first].begin(),Y[it.first].end()) ;
    }
    rep(i,n+2){
        int x = C[i].first , y = C[i].second ;

        auto it = upper_bound(X[x].begin(),X[x].end(),P(x,-1)) ;
        if(it != X[x].end()){
            P p = *it ;
            G[i].push_back(p.second) ;
            G[p.second].push_back(i) ;
        }

        it = upper_bound(Y[y].begin(),Y[y].end(),P(y,-1)) ;
        if(it != Y[y].end()){
            P p = *it ;
            G[i].push_back(p.second) ;
            G[p.second].push_back(i) ;
        }
    }

    djikstra() ;
    if(d[n+1] == 1e6) cout << -1 << endl ;
    else cout << d[n+1] << endl ;
}