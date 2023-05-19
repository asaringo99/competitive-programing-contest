#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

const ll mod = 998244353 ;

ll cal(ll x , ll k , ll mod){
    ll res = 1 ;
    while(k > 0){
        if(k & 1) res = res * x % mod ;
        x = x * x % mod ;
        k >>= 1 ;
    }
    return res % mod ;
}

int par[MAX_N] ; //親
int lank[MAX_N] ; //木の深さ
int siz[MAX_N] ; //木のサイズ

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

bool same(int x , int y){
    return find(x) == find(y) ;
}

int ufsize(int x){
    x = find(x) ;
    return siz[x] ;
}

int main(){
    cin >> n ;
    init(n) ;
    for(int i = 0 ; i < n ; i++){
        int f ;
        cin >> f ;
        f-- ;
        unite(i,f) ;
    }
    set<int> S ;
    for(int i = 0 ; i < n ; i++){
        S.insert(find(i)) ;
    }
    ll N = S.size() ;
    ll ans = cal(2,N,mod) - 1 ;
    cout << ans << endl ;
}