#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , m ;

const int MAX_N = 200007 ;
vector<int> G[MAX_N] , F[MAX_N] ;

struct SCC{
    int n ;
    bool used[MAX_N] , Reused[MAX_N] ;
    ll volume[MAX_N] ;
    vector<int> order ;
    map<int,int> ID ;
    SCC(int n_){
        n = n_ ;
        memset(used,0,sizeof(used)) ;
        memset(Reused,0,sizeof(Reused)) ;
        memset(volume,0,sizeof(volume)) ;
        St() ; Re() ;
    }
    //深さ優先探索
    void dfs(int v){
        used[v] = true ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(!used[u]) dfs(u) ;
        }
        order.push_back(v) ;
    }
    //dfsを順々に行う
    void St(){
        for(int i = 0 ; i < n ; i++){
            if(used[i]) continue ;
            dfs(i) ;
        }
    }

    //後ろから深さ優先探索
    void Redfs(int node , int v){
        ID[v] = node ;
        volume[node]++ ;
        Reused[v] = true ;
        for(int i = 0 ; i < F[v].size() ; i++){
            int u = F[v][i] ;
            if(!Reused[u]) Redfs(node,u) ;
        }
    }
    //Redfsを順々に行う
    void Re(){
        int m = order.size() ;
        for(int i = m - 1 ; i >= 0 ; i--){
            int node = order[i] ;
            if(Reused[node]) continue ;
            Redfs(node,node) ;
        }
    }


    //typical90_21
    ll typical90_21(){
        ll res = 0 ;
        set<int> get ;
        for(int i = 0 ; i < n ; i++) get.insert(ID[i]) ;
        for(int u : get){
            res += volume[u] * (volume[u] - 1) / 2 ;
        }
        return res ;
    }
};

//typical90_21
int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        F[b].push_back(a) ;
    }
    SCC slv(n) ;
    cout << slv.typical90_21() << endl ;
}