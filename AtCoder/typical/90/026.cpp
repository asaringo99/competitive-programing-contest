#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int MAX_N = 100007 ;

int n ;
vector<int> G[MAX_N] ;

bool d[MAX_N] , used[MAX_N] ;

void dfs(){
    memset(d,0,sizeof(d)) ;
    memset(used,0,sizeof(used)) ;
    d[0] = false ;
    queue<int> que ;
    que.push(0) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        used[v] = true ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(!used[u]){
                d[u] = d[v] ? false : true ;
                que.push(u) ; 
            }
        }
    }
}

int main(){
    cin >> n ;
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b ; 
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs() ;
    int m = n / 2 ;
    vector<int> res1 , res2 ;
    for(int i = 0 ; i < n ; i++){
        // cout << d[i] << " " ;
        if(d[i]) res1.push_back(i) ;
        else res2.push_back(i) ;
    }
    if(res1.size() < res2.size()) swap(res1,res2) ;
    for(int i = 0 ; i < m ; i++){
        cout << res1[i] + 1 << " " ;
    }
    cout << endl ;
}