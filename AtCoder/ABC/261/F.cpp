#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

// 座標圧縮
template<typename T=int> struct Compress{
    vector<int> vec ; // 元の値の座標圧縮後の値
    unordered_map<T,int> mp ; // 元の値 -> 変換された値
    unordered_map<int,T> np ; // 変換された値 -> 元の値
    Compress(vector<T> A){
        int n = A.size() ;
        vector<T> B(n) ;
        for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
        vec.resize(n) ;
        sort(A.begin(),A.end()) ;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(A.begin(),A.end(),B[i]) ;
            int id = it - A.begin() ;
            vec[i] = id ;
            mp[B[i]] = id;
            np[id] = B[i] ;
        }
    }
    size_t size() {return vec.size() ; }
    // 元の値 -> 変換された値
    inline int encrypt(T i) { return mp[i] ; }
    // 変換された値 -> 元の値
    inline T decrypt(int i) { return np[i] ; }
    inline int operator [] (int i) { return vec[i] ; }
};

// function         : return              : description
// -----------------------------------------------------
// Compress(vector<ll> A) : void  : コンストラクタ, 座圧する
// encrypt(ll v)          : int   : 元の値 -> 座圧後の値
// decrypt(int v)         : ll    : 座圧後の値 -> 元の値
// operator[i]            : int   : 座圧後の値の vector にアクセスすることが可能


template<typename T>
struct SegmentTree{
    int n , n_;
    vector<T> dat ;
    SegmentTree(int _n){
        n_ = _n ;
        n = 1 ;
        while(n < _n) n *= 2 ;
        dat.resize(2 * n - 1,0) ;
    }
    void add(int k , T x){
        k += n - 1 ;
        dat[k] += x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return lef + rig ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};


int n ;
int C[303030] , X[303030] , Y[303030] ;
vector<P> V[303030] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> C[i] , C[i]-- ;
    rep(i,n) cin >> X[i] , X[i]-- ;
    rep(i,n){
        V[C[i]].push_back(P(X[i],i)) ;
    }
    ll mns = 0 ;
    rep(i,n){
        int m = V[i].size() ;
        vector<int> vec , U ;
        for(P p : V[i]){
            U.push_back(p.first) ;
            vec.push_back(p.second) ;
        }
        Compress C(U) ;
        m = C.size() ;
        SegmentTree<int> S(m) ;
        ll sum = 0 ;
        rep(j,m){
            int x = C[j] ;
            int id = vec[j] ;
            int val = S.query(0,x+1) ;
            sum += j - val ;
            S.add(x,1) ;
            Y[id] = j - val ;
            mns += j - val ;
        }
    }
    SegmentTree<int> S(n) ;
    ll res = 0 ;
    rep(i,n){
        int x = X[i] ;
        int val = S.query(0,x+1) ;
        res += i - val ;
        S.add(x,1) ;
    }
    cout << res - mns << endl ;
}