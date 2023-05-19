#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
vector<int> G[1010] ;
int d[1010][1010] , pre[1010][1010] ;

void dijkstra(int s){
    fill(d[s],d[s]+n,INT_MAX) ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        ll dist = p.first , v = p.second ;
        if(dist < d[s][v] && s != v) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[s][u] > dist + 1){
                d[s][u] = dist + 1 ;
                pre[s][u] = v ;
                que.push(P(d[s][u],u)) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
    }
    int val = INT_MAX ;
    rep(i,n){
        dijkstra(i) ;
        val = min(val,d[i][i]) ;
    }
    if(val == INT_MAX){
        cout << -1 << endl ;
        return 0 ;
    }
    vector<int> res ;
    rep(i,n) if(d[i][i] == val) {
        set<int> st ;
        int u = pre[i][i] ;
        res.push_back(u+1) ;
        while(u != i){
            u = pre[i][u] ;
            res.push_back(u+1) ;
        }
        break ;
    }
    cout << res.size() << endl ;
    for(int u : res) cout << u << endl ;
}