#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
P E[202020] ;
int prevv[404] ;
int d[404] ;
int D[404] ;
vector<int> G[404] ;
bool use[404][404] ;
map<P,bool> mp ;

void dijkstra(){
    rep(i,n) d[i] = 101010 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        for(int i = 0 ; i < G [v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1;
                que.push(P(d[u],u));
                prevv[u] = v ;
            }
        }
    }
    int v = n - 1 ;
    if(d[n-1] == 101010) return ;
    while(v!=0){
        int to = v ;
        v = prevv[v] ;
        use[v][to] = true ;
    }
}
void bfs(int s, int t){
    rep(i,n) D[i] = 101010 ;
    D[0] = 0 ;
    queue<int> que ;
    que.push(0) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(s == v && t == u) continue;
            if(D[u] > D[v] + 1){
                D[u] = D[v] + 1 ;
                que.push(u) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int s , t ;
        cin >> s >> t ;
        s-- ; t-- ;
        G[s].push_back(t) ;
        E[i] = P(s,t) ;
    }
    dijkstra() ;
    for(int i = 0 ; i < m ; i++){
        int s = E[i].first , t=E[i].second ;
        if(use[s][t]){
            bfs(s,t) ;
            if(D[n-1] == 101010) cout << -1 << endl;
            else cout << D[n-1] << endl ;
        }
        else{
            if(d[n-1] == 101010) cout << -1 << endl;
            else cout << d[n-1] << endl;
        }
    }
}