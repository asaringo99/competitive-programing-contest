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
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 1e9 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n , k ;
int A[202020] ;
int B[202020] ;
vector<int> C ;
vector<int> D ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) B[i] = -1 ;
    rep(i,n) cin >> A[i] , A[i]-- ;
    // if(k == n - 1){
    //     cout << 1 << endl ;
    // }
    int val = A[0] ;
    int E = 0 ;
    int m = n ;
    vector<int> vec ;
    rep(i,k){
        if(A[n-1-i] < val){
            vec.push_back(A[n-1-i]) ;
            val = A[n-1-i] ;
            E = i + 1 ;
            m = n - i - 1 ;
        }
    }
    rep(i,vec.size()) C.push_back(vec[vec.size()-1-i]) ;
    rep(i,m) C.push_back(A[i]) ;
    int N = C.size() ;
    k = k - E ;
    rep(i,N) B[C[i]] = i ;
    // rep(i,N) cout << C[i] << " " ; cout << endl ;
    // rep(i,N) D.push_back(C[i]) ;
    // sort(D.begin(),D.end()) ;
    SegmentTree<int> segtree(2*n+1) ;
    rep(i,N) segtree.update(i,C[i]) ;
    int i = 0 ;
    while(i < N){
        cout << C[i] + 1 << " " ;
        i++ ;
        int minval = C[i] ;
        if(k > 0) {
            minval = segtree.query(i,i+k+1) ;
        }
        while(C[i] != minval) {
            k-- ;
            i++ ;
        }
    }
    cout << endl ;
}