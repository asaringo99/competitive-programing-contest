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

struct Compress{
    vector<int> vec ;
    vector<int> compressForArray(int *A , int n){
        vector<int> B(n) ;
        for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
        vec.resize(n) ;
        sort(A,A+n) ;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(A,A+n,B[i]) ;
            vec[i] = it - A ;
        }
        return vec ;
    }
    vector<int> compressForVector(vector<int> A){
        int n = A.size() ;
        vector<int> B(n) ;
        for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
        vec.resize(n) ;
        sort(A.begin(),A.end()) ;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(A.begin(),A.end(),B[i]) ;
            vec[i] = it - A.begin() ;
        }
        return vec ;
    }
};

const int mod = 1000000007 ;

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
        (dat[k] += x) %= mod ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = (dat[2*k+1] + dat[2*k+2]) % mod ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return (lef + rig) % mod ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};


int n , k ;
vector<int> A ;
string S ;

ll dp[2020][2020] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    A.resize(n) ;
    rep(i,n) cin >> A[i] ;
    Compress C ;
    vector<int> vec = C.compressForVector(A) ;
    int maxval = 0 ;
    rep(i,vec.size()) chmax(maxval,vec[i]) ;
    maxval++ ;
    cin >> S ;
    int m = k ;
    rep(i,n-m){
        dp[0][i] = 1 ;
    }
    m++ ;
    rrep(i,1,m){
        SegmentTree<ll> segtree(maxval) ;
        rrep(j,i,n){
            segtree.add(vec[j-1],dp[i-1][j-1]) ;
            ll val ;
            if(S[i-1] == '<') val = segtree.query(0,vec[j]) ;
            else val = segtree.query(vec[j]+1,maxval) ;
            dp[i][j] = val ;
        }
    }
    ll res = 0 ;
    rep(i,n) (res += dp[m-1][i]) %= mod ;
    cout << res << endl ;
}