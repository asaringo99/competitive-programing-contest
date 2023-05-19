#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"


ld DIST(ld sx,ld sy,ld gx,ld gy) {
    return sqrt((sx - gx) * (sx - gx) + (sy - gy) * (sy - gy));
}

struct UnionFind {
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数

    public:
        UnionFind(int n){
            //n要素で初期化
            par.resize(n) ;
            lank.resize(n) ;
            volume.resize(n) ;
            edge.resize(n) ;
            for(int i = 0 ; i < n ; i++){
                par[i] = i ;
                lank[i] = 0 ;
                volume[i] = 1 ;
                edge[i] = 0 ;
            }
        }
        //木の根を求める
        int root(int x) {
            if(par[x] == x) return x ;
            else return par[x] = root(par[x]) ;
        }

        //xとyの属する集合を合併
        void unite(int x , int y){
            x = root(x);
            y = root(y) ;
            if(x == y) {
                edge[x]++ ;
                return ;
            }
            if(lank[x] < lank[y]){
                par[x] = y ;
                volume[y] += volume[x] ;
                edge[y] += edge[x] + 1 ;
            } else {
                par[y] = x ;
                volume[x] += volume[y] ;
                edge[x] += edge[y] + 1 ;
                if(lank[x] == lank[y]) lank[x]++ ;
            }
        }

        bool same(int x , int y) { return root(x) == root(y) ; }
        int size(int x) { return volume[root(x)] ; }
        int edge_num(int x) { return edge[root(x)] ; }
};

int n, m;


int main(){
    fast_io
    cin >> n >> m;
    vector<tuple<int,int,int>> X(n), Y(m);
    rep(i,n){
        int a, b, c;
        cin >> a >> b >> c;
        X[i] = {a,b,c};
    }
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        Y[i] = {a,b,c};
    }
    vector<tuple<ld,int,int>> E;
    rep(i,n){
        rrep(j,i+1,n){
            auto[a,b,c] = X[i];
            auto[x,y,d] = X[j];
            ld dist = DIST(a,b,x,y);
            if(c != d) dist *= 10;
            E.push_back({dist,i,j});
        }
    }
    ld res = 1e18;
    rep(S, 1<<m){
        vector<int> vec;
        rep(i,m) if(S >> i & 1) vec.push_back(i);
        int cnt = vec.size();
        auto F = E;
        rep(i,n){
            rep(j,cnt){
                auto[a,b,c] = X[i];
                auto[x,y,d] = Y[vec[j]];
                ld dist = DIST(a,b,x,y);
                if(c != d) dist *= 10;
                F.push_back({dist,i,n+vec[j]});
            }
        }
        rep(i,cnt){
            rrep(j,i+1,cnt){
                auto[a,b,c] = Y[vec[i]];
                auto[x,y,d] = Y[vec[j]];
                ld dist = DIST(a,b,x,y);
                if(c != d) dist *= 10;
                F.push_back({dist,n+vec[i],n+vec[j]});
            }
        }
        UnionFind uf(n+m);
        sort(all(F));
        ld sum = 0;
        rep(i,F.size()){
            auto[dist,a,b] = F[i];
            if(uf.same(a,b)) continue;
            uf.unite(a,b);
            sum += dist;
        }
        chmin(res,sum);
    }
    cout << fixed << setprecision(25) << res << endl;
}