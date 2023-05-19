#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N 200005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , K , L ;

int par[MAX_N] ; //親
int lank[MAX_N] ; //木の深さ
vector<int> road[MAX_N] , train[MAX_N] ;
int table[MAX_N] ;
bool used1[MAX_N] ;
bool used2[MAX_N] ;

//n要素で初期化

void init(int n) {
    for(int i = 0 ; i < n ; i++){
        par[i] = i ;
        lank[i] = 0 ;
    }
}

//木の根を求める
int find(int x){
    if(par[x] == x){
        return x ;
    } else{
        return par[x] = find(par[x]) ;
    }
}

//xとyの属する集合を合併
void unite(int x , int y){
    x = find(x) ;
    y = find(y) ;
    if(x == y) return ;

    if(lank[x] < lank[y]){
        par[x] = y ;
    } else {
        par[y] = x ;
        if(lank[x] == lank[y]) lank[x]++ ;
    }
}

bool same(int x , int y){
    return find(x) == find(y) ;
}

int main(){
    cin >> n >> K >> L ;
    init(n) ;
    memset(used1,0,sizeof(used1)) ;
    memset(used2,0,sizeof(used2)) ;
    for(int i = 0 ; i < K ; i++){
        int p , q ;
        cin >> p >> q ;
        p-- ; q-- ;
        unite(p,q) ;
    }
    for(int i = 0 ; i < n ; i++){
        table[i] = find(i) ;
    }
    for(int i = 0 ; i < n ; i++){
        road[table[i]].push_back(i) ;
    }
    init(n) ;
    for(int i = 0 ; i < L ; i++){
        int r , s ;
        cin >> r >> s ;
        r-- ; s-- ;
        unite(r,s) ;
    }
    set<int> st ;
    for(int i = 0 ; i < n ; i++){
        train[find(i)].push_back(i) ;
        st.insert(find(i)) ;
    }
    int res[n] ;
    fill(res,res+n,1) ;
    for(int u : st){
        vector<int> node ;
        int v = table[u] ;
        sort(road[v].begin(),road[v].end()) ;
        for(int s : train[u]){
            auto it = lower_bound(road[v].begin(),road[v].end(),s) ;
            if(*it == s) node.push_back(s) ;
        }
        for(int i : node){
            res[i] = node.size() ;
        }
    }
    for(int u : res) cout << u << " " ;
    cout << endl ;
}