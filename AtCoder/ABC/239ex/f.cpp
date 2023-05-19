#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

template<typename T>
struct UnionFind {
    vector<T> par ; //親
    vector<T> lank ; //木の深さ
    vector<T> volume ; //木のサイズ
    UnionFind(T n){
        //n要素で初期化
        par.resize(n) ;
        lank.resize(n) ;
        volume.resize(n) ;
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
int D[202020] , C[202020] ;

priority_queue<P> que ;

vector<int> G[202020] ;
vector<int> node[202020] ;
set<int> id ;

int main(){
    cin >> n >> m ;
    UnionFind<ll> uf(n) ;
    ll sum = 0 ;
    rep(i,n) cin >> D[i] , sum += D[i] ;
    if(sum != 2 * n - 2){
        cout << -1 << endl ;
        return 0 ;
    }
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        uf.unite(a,b) ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
        D[a]-- ;
        D[b]-- ;
        if(D[a] < 0 || D[b] < 0){
            cout << -1 << endl ;
            return 0 ;
        }
    }
    rep(i,n){
        C[uf.root(i)] += D[i] ;
        id.insert(uf.root(i)) ;
        rep(j,D[i]) node[uf.root(i)].push_back(i) ;
    }
    for(int u : id){
        que.push(P(C[u],u)) ;
    }
    auto [c,v] = que.top() ; que.pop() ;
    vector<P> res ;
    vector<int> base = node[v] ;
    while(!que.empty()){
        auto [cnt,k] = que.top() ; que.pop() ;
        if(cnt == 0){
            cout << -1 << endl ;
            return 0 ;
        }
        int b = base.size() ;
        int p = node[k].size() ;
        res.push_back(P(base[b-1]+1,node[k][p-1]+1)) ;
        base.pop_back() ;
        node[k].pop_back() ;
        for(int u : node[k]) base.push_back(u) ;
    }
    for(P p : res) cout << p.first << " " << p.second << endl ;
}