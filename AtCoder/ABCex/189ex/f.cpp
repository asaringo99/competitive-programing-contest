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
    int n ;
    vector<T> dat ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        dat.resize(2 * n - 1,0) ;
    }
    void update(int k , T x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
    }
    T query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = query(a,b,2*k+2,(l+r)/2,r) ;
        return lef + rig ;
    }
    T query(int a , int b){
        return query(a,b,0,0,n) ;
    }
};

int n , m , k ;
bool A[101010] ;

int main(){
    cin >> n >> m >> k ;
    SegmentTree<ld> X(n+1) , C(n+1) ;
    rep(i,k){
        int a ;
        cin >> a ;
        A[a] = true ;
        X.update(a,1) ;
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(A[i]) continue ;
        ld x = X.query(i+1,min(i+m+1,n+1)) / m ;
        ld c = C.query(i+1,min(i+m+1,n+1)) / m ;
        X.update(i,x) ;
        C.update(i,c+1) ;
    }
    ld e = 1 - X.query(0,1) ;
    if(abs(e) <= 1e-8) cout << -1 << endl ;
    else cout << fixed << setprecision(25) << C.query(0,1) / e << endl ;
}