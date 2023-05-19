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

template <typename T>
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
            lazy.resize(2*n-1,inf) ;
        }
        void eval(int k){
            if(lazy[k] == inf) return ;
            if(k < n - 1){
                lazy[2*k+1] = lazy[k] ;
                lazy[2*k+2] = lazy[k] ;
            }
            dat[k] = lazy[k] ;
            lazy[k] = inf ;
        }

        void update_(int a , int b , int k , int l , int r , T x){
            eval(k) ;
            if(r <= a || b <= l) return ;
            if(a <= l && r <= b) {
                lazy[k] = x ;
                eval(k) ;
                return ;
            }
            update_(a,b,2*k+1,l,(l+r)/2,x) ;
            update_(a,b,2*k+2,(l+r)/2,r,x) ;
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }

        void update_(int a , int b , T x){
            update_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            eval(k) ;
            if(r <= a || b <= l) return inf ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return min(lef,rig) ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n) ;
        }

    public :
        LazySegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void update(int a , int b , T x) { update_(a,b,x) ; }
};

ll n, c;
ll H[202020];
ll dp[202020];
int prevv[202020];

ll f(int i, int j){
    return (H[i] - H[j]) * (H[i] - H[j]);
}

int main(){
    cin >> n >> c;
    rep(i,n) cin >> H[i];
    H[n] = 2e9;
    dp[1] = 0;
    prevv[2] = 1;
    int k = 1;
    LazySegmentTree<ll> segtree(n+1);
    segtree.update(2,n+1,1);
    rrep(i,2,n+1){
        k = segtree.query(i,i+1);
        dp[i] = dp[k] + f(k-1,i-1) + c;
        int lef = i, rig = n+1;
        while(rig - lef > 1){
            int mid = (lef + rig) / 2;
            ll a = dp[i-1] + f(i-2,mid-1) + c;
            ll b = dp[i] + f(i-1,mid-1) + c;
            if(a > b) rig = mid;
            else lef = mid;
        }
        segtree.update(rig,n+1,i);
    }
    // cout << endl;
    cout << dp[n] << endl;
}