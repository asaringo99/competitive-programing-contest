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
struct LazySegmentTree{
    private :
        const ll linf = 1e18 ;
        const int inf = 1e8 ;

        int n , n_ ;
        vector<T> dat , lazy ;

        void build(){
            n = 1 ;
            while(n < n_) n *= 2 ;
            dat.resize(2*n-1,0) ;
            lazy.resize(2*n-1,-inf) ;
        }

        // 遅延評価
        void eval(int k){
            if(lazy[k] == inf) return ;
            if(k < n - 1){
                lazy[2 * k + 1] = lazy[k] / 2 ;
                lazy[2 * k + 2] = lazy[k] / 2 ;
            }
            dat[k] = lazy[k] ;
            lazy[k] = inf ;
        }

        // 区間加算
        void update_(int a , int b , int k , int  l , int r , T w){
            eval(k) ;
            if(b <= l || r <= a) return ;
            if(a <= l && r <= b) {
                // 区間加算
                lazy[k] = (r - l) * w ;
                eval(k) ;
                return ;
            }
            update_(a,b,2*k+1,l,(l+r)/2,w) ;
            update_(a,b,2*k+2,(l+r)/2,r,w) ;
            // 区間の更新をする必要がある
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
        void update_(int a , int b , T x){
            return update_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            //遅延評価（これは確実に必要）
            eval(k) ;
            if(b <= l || r <= a) return 0 ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return lef + rig ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n)  ;
        }

    public :
        LazySegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void update(int a , int b , T x) { update_(a,b,x) ; }
};

int n , q , x ;
int p[202020] ;

int main(){
    cin >> n >> q >> x ;
    int id = -1 ;
    LazySegmentTree<int> segtree(n) ;
    rep(i,n) cin >> p[i] ;
    rep(i,n){
        if(p[i] < x) segtree.update(i,i+1,1) ;
        else segtree.update(i,i+1,0) ;
        if(p[i] == x) id = i ;
    }
    rep(i,q){
        int c , l , r ;
        cin >> c >> l >> r ;
        l-- ;
        int query = segtree.query(l,r) ;
        if(c == 1){
            segtree.update(l,l+query,1) ;
            segtree.update(l+query,r,0) ;
            if(l <= id && id < r) id = l + query ;
        }
        if(c == 2){
            segtree.update(l,r-query,0) ;
            segtree.update(r-query,r,1) ;
            if(l <= id && id < r) id = r-1-query ;
        }
    }
    cout << id + 1 << endl ;
}