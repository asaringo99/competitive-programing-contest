#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m , s , t ;
vector<int> G[101010] ;
ll d[101010][3] ;

void f(int s){
    rep(i,n) rep(j,3) d[i][j] = 1e16 ;
    d[s][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,s,0}) ;
    while(!que.empty()){
        ll dist , v , cnt ;
        tie(dist,v,cnt) = que.top() ; que.pop() ;
        if(d[v][cnt] < dist) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(cnt == 2 && d[u][0] > d[v][cnt] + 1){
                d[u][0] = d[v][cnt] + 1 ;
                que.push({d[u][0],u,0}) ;
            }
            else if(cnt < 2 && d[u][cnt+1] > d[v][cnt]){
                d[u][cnt+1] = d[v][cnt] ;
                que.push({d[u][cnt+1],u,cnt+1}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
    }
    cin >> s >> t ;
    s-- ; t-- ;
    f(s) ;
    ll res = d[t][0] == 1e16 ? -1 : d[t][0] ;
    cout << res << endl ;
}