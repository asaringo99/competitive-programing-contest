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
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 1e18 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n , d ;
ll A[400][3030] ;
ll dp[400][3030][4] ;

int main(){
    cin >> n >> d ;
    rep(i,d) rep(j,n) cin >> A[i][j] ;
    SegmentTree<ll> d1(n) , d2(n) , d3(n) ;
    rep(i,d) rep(j,n) rrep(k,1,4) dp[i][j][k] = 1e16 ;
    rep(i,n) dp[0][i][1] = A[0][i] , d1.update(i,A[0][i]) , d2.update(i,1e16) , d3.update(i,1e16) ;
    rrep(i,1,d){
        rep(j,n) {
            ll l1 = d1.query(0,n) , l2 = d2.query(0,n) , l3 = d3.query(0,n) ;
            dp[i][j][1] = A[i][j] + min({l1,l2,l3}) ;
            dp[i][j][2] = A[i][j] / 10 * 9 + dp[i-1][j][1] ;
            dp[i][j][3] = A[i][j] / 10 * 7 + min(dp[i-1][j][2],dp[i-1][j][3]) ;
        }
        rep(j,n){
            d1.update(j,dp[i][j][1]) ;
            d2.update(j,dp[i][j][2]) ;
            d3.update(j,dp[i][j][3]) ;
        }
    }
    ll res = 1e16 ;
    rep(i,n) rrep(j,1,4) chmin(res,dp[d-1][i][j]) ;
    cout << res << endl ;
}