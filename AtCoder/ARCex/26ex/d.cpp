#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,ld,ld> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int MAX_N = 10101 ;

template<typename T>
struct UnionFind {
    T par[MAX_N] ; //親
    T lank[MAX_N] ; //木の深さ
    T volume[MAX_N] ; //木のサイズ
    UnionFind(T n){
        //n要素で初期化
        for(int i = 0 ; i < n ; i++){
            par[i] = i ;
            lank[i] = 0 ;
            volume[i] = 1 ;
        }
    }
    //木の根を求める
    T root(T x){
        if(par[x] == x){
            return x ;
        } else{
            return par[x] = root(par[x]) ;
        }
    }

    //xとyの属する集合を合併
    void unite(T x , T y){
        x = root(x);
        y = root(y) ;
        if(x == y) return ;

        if(lank[x] < lank[y]){
            par[x] = y ;
            volume[y] += volume[x] ;
        } else {
            par[y] = x ;
            if(lank[x] == lank[y]) lank[x]++ ;
            volume[x] += volume[y] ;
        }
    }

    bool same(T x , T y){
        return root(x) == root(y) ;
    }

    T size(T x){
        return volume[root(x)] ;
    }
} ;

int n , m ;
TP X[10101] ;

bool f(ld x){
    using TTP = tuple<ld,int,int> ;
    vector<TTP> vec ;
    rep(i,m){
        int a , b ;
        ld c , t ;
        tie(a,b,c,t) = X[i] ;
        vec.push_back({c-x*t,a,b}) ;
    }
    sort(vec.begin(),vec.end()) ;
    UnionFind<int> uf(n) ;
    ld sum = 0 ;
    for(TTP ttp : vec){
        int a , b ;
        ld v ;
        tie(v,a,b) = ttp ;
        if(v < 0){
            sum += v ;
            uf.unite(a,b) ;
        }
        if(uf.same(a,b)) continue ;
        if(sum + v > 0) break ;
        sum += v ;
        uf.unite(a,b) ;
    }
    return uf.size(0) == n ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        ld c , t ;
        cin >> a >> b >> c >> t ;
        X[i] = {a,b,c,t} ;
    }
    int count = 0 ;
    ld lef = 0 , rig = 1e18 ;
    while(count < 100){
        ld mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
        count++ ;
    }
    cout << fixed << setprecision(25) << rig << endl ;
}