#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

vector<int> G[MAX_N] ;
int d[MAX_N] ;
bool used1[MAX_N] , used2[MAX_N] ;

vector<int> res ;

void dfs1(int v , int score){
    d[v] = score ;
    used1[v] = true ;
    int res = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(!used1[u]) dfs1(u,score + 1) ;
    }
    return ;
}

int dfs2(int v , int score){
    used2[v] = true ;
    if(G[v].size() == 1 && used2[G[v][0]]) return score ;
    int res = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(!used2[u]) res = max(res,dfs2(u,score+1)) ;
    }
    return res ;
}
int main(){
    cin >> n ;
    memset(used1,0,sizeof(used1)) ;
    memset(used2,0,sizeof(used2)) ;
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs1(0,0) ;
    int dis = -1 , num = -1 ;
    for(int i = 0 ; i < n ; i++){
        if(dis < d[i]){
            dis = d[i] ;
            num = i ;
        }
    }
    cout << dfs2(num,0) + 1 << endl ;
}