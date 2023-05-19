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
        dat.resize(2 * n - 1,-1e18) ;
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
        if(r <= a || b <= l) return -1e18 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n ;
P A[505050] ;
ll S[505050] ;

int main(){
    cin >> n ;
    SegmentTree<ll> segtree(n+1) ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        A[i] = P(a,b) ;
    }
    sort(A,A+n) ;
    ll sum = 0 ;
    rep(i,n){
        auto [a,b] = A[i] ;
        sum += b ;
        S[i] = sum - a ;
        segtree.update(i,S[i]) ;
    }
    ll res = 0 ;
    rep(i,n){
        auto [a,b] = A[i] ;
        chmax(res,segtree.query(i,n+1)-S[i]+b) ;
    }
    cout << res << endl ;
}