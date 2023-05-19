#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

const int MAX_N = 400005 ;


int n ;

int par[400005] ; //親
int lank[400005] ; //木の深さ
int siz[400005] ; //木のサイズ
int edge[400005] ; //辺の数
vector<int> G[400005] ; //node -> node

//n要素で初期化
void init(int n) {
    for(int i = 0 ; i < n ; i++){
        par[i] = i ;
        lank[i] = 0 ;
        siz[i] = 1 ;
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
        siz[y] += siz[x] ;
    } else {
        par[y] = x ;
        if(lank[x] == lank[y]) lank[x]++ ;
        siz[x] += siz[y] ;
    }
}

//同じ連結成分かどうか
bool same(int x , int y){
    return find(x) == find(y) ;
}

//node xが所属している連結成分の頂点数
int ufsize(int x){
    x = find(x) ;
    return siz[x] ;
}

//各連結成分の辺の数
void edgenum(int n){
    memset(edge,0,sizeof(edge)) ;
    for(int i = 0 ; i < n ; i++){
        edge[find(i)] += G[i].size() ;
    }
    for(int i = 0 ; i < n ; i++){
        edge[i] /= 2 ;
    }
}

int main(){
    cin >> n ;
    init(400005) ;
    for(int i = 0 ; i < n ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        unite(a,b) ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    edgenum(400005) ;
    ll sum = 0 ;
    bool used[400005] ;
    for(int i = 0 ; i < 400005 ; i++){
        int x = find(i) , N , E ;
        if(used[x]) continue ;
        used[x] = true ;
        N = siz[x] ;
        E = edge[x] ;
        if(N - 1 == E) sum += N - 1 ;
        else sum += N ;
    }
    cout << sum << endl ;
}