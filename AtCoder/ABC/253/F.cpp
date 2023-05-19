#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int,ll> TP ;
typedef tuple<int,int,ll> TTP ;
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
            lazy.resize(2*n-1,0) ;
        }

        // 遅延評価
        void eval(int k){
            dat[k] += lazy[k] ;
            if(k < n - 1){
                lazy[2 * k + 1] += lazy[k] / 2 ;
                lazy[2 * k + 2] += lazy[k] / 2 ;
            }
            lazy[k] = 0 ;
        }

        // 区間加算
        void add_(int a , int b , int k , int  l , int r , T w){
            eval(k) ;
            if(b <= l || r <= a) return ;
            if(a <= l && r <= b) {
                // 区間加算
                lazy[k] += (r - l) * w ;
                eval(k) ;
                return ;
            }
            add_(a,b,2*k+1,l,(l+r)/2,w) ;
            add_(a,b,2*k+2,(l+r)/2,r,w) ;
            // 区間の更新をする必要がある
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
        void add_(int a , int b , T x){
            return add_(a,b,0,0,n,x) ;
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
        void add(int a , int b , T x) { add_(a,b,x) ; }
};

int n , m , q ;
TP Q[202020] ;
vector<TTP> vec[202020] ;

int main(){
    // fast_input_output
    cin >> n >> m >> q ;
    LazySegmentTree<ll> segtree(m) ;
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            int l , r ;
            ll x ;
            cin >> l >> r >> x ;
            l-- ;
            Q[i] = {t,l,r,x} ;
        }
        if(t == 2){
            int r , x ;
            cin >> r >> x ;
            r-- ;
            Q[i] = {t,r,x,-1} ;
        }
        if(t == 3){
            int x , y ;
            cin >> x >> y ;
            x-- ; y-- ;
            Q[i] = {t,x,y,-1} ;
        }
    }
    vector<P> res ;
    for(int i = q - 1 ; i >= 0 ; i--){
        int l , r , row , col ;
        ll x ;
        auto [t,a,b,c] = Q[i] ;
        if(t == 1){
            l = a ;
            r = b ;
            x = c ;
            segtree.add(l,r,x) ;
        }
        if(t == 2){
            row = a ;
            x = b ;
            while(!vec[row].empty()){
                int s = vec[row].size() - 1 ;
                auto[id,col,val] = vec[row][s] ;
                ll tmp = segtree.query(col,col+1) ;
                res.push_back(P(id,tmp-val+x)) ;
                vec[row].pop_back() ;
            }
        }
        if(t == 3){
            row = a ;
            col = b ;
            ll val = segtree.query(col,col+1) ;
            vec[row].push_back({i,col,val}) ;
        }
    }

    rep(row,n){
        while(!vec[row].empty()){
            int s = vec[row].size() - 1 ;
            auto[id,col,val] = vec[row][s] ;
            ll tmp = segtree.query(col,col+1) ;
            res.push_back(P(id,tmp-val)) ;
            vec[row].pop_back() ;
        }
    }

    sort(res.begin(),res.end()) ;
    for(P p : res) cout << p.second << endl ;
}