#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
string first , last ;
string S[1010] ;

vector<int> G[1010] ;
int d[1010] , prevv[1010] ;
vector<int> vec ;

void bfs(){
    rep(i,n+2) d[i] = 1e8 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                prevv[u] = v ;
                que.push(P(d[u],u)) ;
            }
        }
    }
}

int main(){
    cin >> first >> last >> n ;
    S[0] = first ; S[n+1] = last ;
    rrep(i,1,n+1) cin >> S[i] ;
    rep(i,n+2) rep(j,n+2) {
        int cnt = 0 ;
        rep(k,first.size()) if(S[i][k] != S[j][k]) cnt++ ;
        if(cnt <= 1) G[i].push_back(j) ;
    }
    bfs() ;
    if(d[n+1] == 1e8) cout << -1 << endl ;
    else {
        cout << d[n+1] - 1 << endl ;
        int v = n + 1 ;
        while(v != 0){
            vec.push_back(v) ;
            v = prevv[v] ;
        }
        cout << S[0] << endl ;
        rep(i,vec.size()) cout << S[vec[vec.size() - 1 - i]] << endl ;
    }
}