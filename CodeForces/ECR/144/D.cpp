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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename T>
struct LazySegmentTree{
    private :
        const ll linf = 1e18 ;

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
                lazy[2 * k + 1] += lazy[k] ;
                lazy[2 * k + 2] += lazy[k] ;
            }
            lazy[k] = 0 ;
        }

        // 区間加算
        void add_(int a , int b , int k , int  l , int r , T w){
            eval(k) ;
            if(b <= l || r <= a) return ;
            if(a <= l && r <= b) {
                // 区間加算
                lazy[k] += w ;
                eval(k) ;
                return ;
            }
            add_(a,b,2*k+1,l,(l+r)/2,w) ;
            add_(a,b,2*k+2,(l+r)/2,r,w) ;
            // 区間の更新をする必要がある
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }
        void add_(int a , int b , T x){
            return add_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            //遅延評価（これは確実に必要）
            eval(k) ;
            if(b <= l || r <= a) return linf ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return min(lef,rig) ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n)  ;
        }
    
    public :
        LazySegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void add(int a , int b , T x) { add_(a,b,x) ; }
};

ll n, k, x;

ll f(vector<ll> A){
    LazySegmentTree<ll> segtree(n+1);
    ll sum = 0;
    rrep(i,1,n+1){
        sum += A[i-1];
        segtree.add(i,i+1,sum);
    }
    ll res = 0;
    rrep(i,1,n+1){
        segtree.add(i,n+1,x);
        if(i - k > 0){
            segtree.add(i-k,n+1,-x*2);
        }
        ll now = segtree.query(i,i+1);
        ll y = segtree.query(0,i+1);
        chmax(res,now-y);
        chmax(res,y-now);
    }
    return res;
}

void solve(){
    cin >> n >> k >> x;
    if(x < 0){
        k = n - k;
        x = abs(x);
    }
    vector<ll> A(n), S(n+1);
    rep(i,n) cin >> A[i];
    ll res = 0;
    chmax(res,f(A));
    reverse(all(A));
    chmax(res,f(A));
    cout << res << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}