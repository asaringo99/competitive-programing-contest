#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,ll,int> TP ;
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

int n , m , q ;
vector<TP> ge ; //時間, 0:投入 1:出発 2:到着 3:クエリ, どのnodeか  member, バス
int mapping[101010] ;
int status[101010] ;// 0:nodeにいる, 1:バスにいる
multiset<TP> tim ;
int X[101010] , Y[101010] ;
P bus[101010] ;
P res[101010] ;

int main(){
    cin >> n >> m >> q ;
    rep(i,m){
        int a , b , s , t ;
        cin >> a >> b >> s >> t ;
        a-- ; b-- ;
        X[i] = a , Y[i] = b ;
        tim.insert({s,3,a,-1,i}) ;
        ge.push_back({t,2,b,-1,-1}) ;
    }
    rep(i,q){
        int x , y , z ;
        cin >> x >> y >> z ;
        y-- ;
        tim.insert({x,1,y,i,-1}) ;
        tim.insert({z,0,-1,i,i}) ;
    }
    rep(i,n) mapping[i] = -1 ;
    UnionFind<ll> uf(q) ;
    auto it = tim.begin() ;
    while(it != tim.end()){
        int t , query , node , member , edge ;
        tie(t,query,node,member,edge) = *it ;
        if(query == 1){
            if(mapping[node] != -1){
                uf.unite(mapping[node],member) ;
                int root = uf.root(member) ;
                mapping[node] = root ;
                status[root] = node ;
            }
            else{
                status[member] = node ;
                mapping[node] = member ;
            }
        }
        if(query == 3){
            if(mapping[node] != -1){
                int root = uf.root(mapping[node]) ;
                status[root] = -1 ;
                mapping[node] = -1 ;
                int a , b , c , d , e ;
                bus[root] = P(X[edge],Y[edge]) ;
                tie(a,b,c,d,e) = ge[edge] ;
                tim.insert({a,b,c,root,e}) ;
            }
        }
        if(query == 2){
            if(mapping[node] != -1){
                uf.unite(mapping[node],member) ;
                int root = uf.root(member) ;
                status[root] = node ;
                mapping[node] = root ;
            }
            else{
                status[member] = node ;
                mapping[node] = member ;
            }
        }
        if(query == 0){
            int root = uf.root(member) ;
            if(status[root] == -1) res[edge] = bus[root] ;
            else res[edge] = P(status[root],-1) ;
        }
        it++ ;
    }
    rep(i,q){
        if(res[i].second == -1) cout << res[i].first + 1 << endl ;
        else cout << res[i].first + 1 << " " << res[i].second + 1 << endl ;
    }
}