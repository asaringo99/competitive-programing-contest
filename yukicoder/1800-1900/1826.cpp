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

const int MAX_N = 1 << 18 ;

template<typename T>
struct SegmentTree{
    int n ;
    T dat[2 * MAX_N - 1] ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,0,sizeof(dat)) ;
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

template<typename T> struct Compress{
    vector<int> vec ;
    unordered_map<T,ll> mp ;
    Compress(vector<T> A){
        int n = A.size() ;
        vector<int> B(n) ;
        for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
        vec.resize(n) ;
        sort(A.begin(),A.end()) ;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(A.begin(),A.end(),B[i]) ;
            vec[i] = it - A.begin() ;
            mp[B[i]] = it - A.begin();
        }
    }
    inline int compress(ll i) { return mp[i] ; }
    inline int operator [] (int i) { return vec[i] ; }
};

int n ;
vector<TP> X ;
vector<ll> vec ;

int main(){
    cin >> n ;
    rep(i,n){
        ll t , x , v ;
        cin >> t >> x >> v ;
        if(abs(x)>t) continue ;
        X.push_back({x+t,t-x,v}) ;
        vec.push_back(t-x) ;
    }
    sort(X.begin(),X.end()) ;
    Compress<ll> s(vec) ;
    SegmentTree<ll> segtree(n) ;
    for(int i = X.size() - 1 ; i >= 0 ; i--){
        ll x , y , v ;
        tie(x,y,v) = X[i] ;
        ll k = s.compress(y) ;
        ll val = segtree.query(k,n) ;
        segtree.update(k,val+v) ;
    }
    cout << segtree.query(0,n) << endl ;
}