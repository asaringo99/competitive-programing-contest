#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename S , typename M>
struct LazySegmentTree{
    private :
        int n , _n ;
        using FS = function<S(S,S)> ;
        using FM = function<M(M,M)> ;
        using FA = function<S(S,M)> ;
        FS fs ;
        FM fm ;
        FA fa ;
        S es ;
        M em ;
        vector<S> dat ;
        vector<M> lazy ;
        
        // 各セグメントに左端値, 右端値を持たせる
        void build(){
            int id = 0 ;
            for(int i = n ; i > 0 ; i = i / 2){
                for(int j = 0 ; j < n ; j += i){
                    dat[id].lef = j ;
                    dat[id].rig = j + i ;
                    id++ ;
                }
            }
        }
        void eval(int k , int l , int r){
            if(lazy[k] == em) return ;
            int len = (r - l) / 2 ;
            if(k < n - 1) {
                lazy[2 * k + 1] = fm(lazy[2 * k + 1] , {lazy[k].a,lazy[k].b}) ;
                lazy[2 * k + 2] = fm(lazy[2 * k + 2] , {lazy[k].a,lazy[k].a*len+lazy[k].b}) ;
            }
            dat[k] = fa(dat[k],lazy[k]) ;
            lazy[k] = em ;
        }
        void apply(int a , int b , int k , int l , int r , M x){
            eval(k,l,r) ;
            if(r <= a || b <= l) return ;
            if(a <= l && r <= b) {
                lazy[k] = fm(lazy[k],{x.a,x.a*(l-a)+x.b}) ;
                eval(k,l,r) ;
                return ;
            }
            apply(a,b,2*k+1,l,(l+r)/2,x) ;
            apply(a,b,2*k+2,(l+r)/2,r,x) ;
            dat[k] = fs(dat[2*k+1],dat[2*k+2]) ;
        }
        S prod(int a , int b , int k , int l , int r) {
            eval(k,l,r) ;
            if(r <= a || b <= l) return es ;
            if(a <= l && r <= b) return dat[k] ;
            S lef = prod(a,b,2*k+1,l,(l+r)/2) ;
            S rig = prod(a,b,2*k+2,(l+r)/2,r) ;
            return fs(lef,rig) ;
        }
    
    public :
        LazySegmentTree(int n_ , FS fs_ , S es_ , S ee_ , FM fm_ , M em_ , FA fa_) : fs(fs_) , fm(fm_) , fa(fa_) , es(es_) , em(em_) {
            _n = n_ ;
            n = 1 ;
            while(n_ > n) n *= 2 ;
            dat.resize(2 * n - 1,ee_) ;
            lazy.resize(2 * n - 1,em) ;
            build() ;
        }
        void apply(int a , int b , M x) { apply(a,b,0,0,n,x) ; }
        S prod(int a , int b) { return prod(a,b,0,0,n) ; }
};

namespace monoid{
    ll linf = 1e16 ;
    int inf = 1e8 ;

    // モノイド
    struct S{
        ll sum ;
        int lef , rig ;
    };

    // S*S->Sにおける演算の定義
    function<S(S,S)> fs = [](S x , S y) -> S {
        return S{
            x.sum + y.sum,
            x.lef,
            y.rig
        };
    };
    
    // Sの単位元
    S es = {0,inf,-inf} ;

    // Sの初期化単位元
    S ee = {0,0,0} ;

    // 作用モノイド
    struct M{
        ll a , b ;
        bool operator == (M x) { return a == x.a && b == x.b ; }
    };

    // M*M->Mにおける演算の定義1
    function<M(M,M)> fm = [](M x , M y) -> M {
        return M{
            x.a + y.a,
            x.b + y.b
        };
    };

    // Mの単位元
    M em = {0,0} ;

    // S*M->Sにおける演算の定義
    function<S(S,M)> fa = [](S x , M y) -> S {
        int len = (x.rig - x.lef) ;
        int lef = x.lef ;
        return S{
            x.sum + len * (len - 1) / 2 * y.a + len * y.b ,
            x.lef,
            x.rig,
        };
    };
};
using namespace monoid ;

// monoid
// S    : sum(区間和) , lef(区間左端値), rig(区間右端値) 
// M    : (a,b) -> ax + b のモノイド
// apply: 区間等差数列加算
// prod : sum(区間和), min(区間最小値), max(区間最大値)

// verified: https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2020Day1/problems/B

int n , m;
int A[101010];

int main(){
    cin >> n >> m;
    rep(i,n) cin >> A[i];
    LazySegmentTree<S,M> segtree(m,fs,es,ee,fm,em,fa);
    ll res = 0;
    rep(i,n-1){
        int x = A[i];
        int y = A[i+1];
        res += (y - x + m) % m;
        if(x > y){
            segtree.apply(x,m,{1,0});
            segtree.apply(0,y,{1,m-x});
        }
        else{
            segtree.apply(x,y,{1,0});
        }
    }
    ll val = 0;
    rep(i,m) {
        chmax(val,segtree.prod(i,i+1).sum);
    }
    cout << res - val << endl;
}