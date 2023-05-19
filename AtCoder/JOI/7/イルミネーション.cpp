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
struct SegmentTree{
    int n , n_;
    vector<T> dat ;
    SegmentTree(int _n){
        n = 1 ;
        n_ = _n ;
        while(n < _n) n *= 2 ;
        dat.resize(2 * n - 1,0) ;
    }
    void update(int k , T x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = max(dat[2*k+1],dat[2*k+2]) ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n , m ;
ll A[202020] ;
P X[202020] ;
int L[202020] ;
ll dp[202020] ;

int main(){
    cin >> n >> m ;
    SegmentTree<ll> segtree(n) ;
    rep(i,n) cin >> A[i];
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        X[i] = P(a,-b) ;
    }
    sort(X,X+m) ;
    ll p = 0 ;
    rep(i,n) L[i] = i ;
    rep(i,m){
        auto [a,b] = X[i] ;
        b = -b ;
        p = max(p,a) ;
        while(p < b){
            L[p] = a ;
            p++ ;
        }
    }
    rep(i,n){
        int s = L[i] ;
        dp[i] = segtree.query(0,s) + A[i] ;
        segtree.update(i,dp[i]) ;
    }
    ll res = 0 ;
    rep(i,n) chmax(res,dp[i]) ;
    cout << res << endl ;
}