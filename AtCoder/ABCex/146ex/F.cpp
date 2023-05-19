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
int dp[101010] ;
int pre[101010] ;
string S ;

int main(){
    cin >> n >> m >> S ;
    reverse(S.begin(),S.end()) ;
    SegmentTree<ll> segtree(n+1) ;
    rep(i,n+1) {
        if(S[i] == '1') segtree.update(i,0) ;
        if(S[i] == '0') segtree.update(i,i) ;
    }
    rep(i,n+1) dp[i] = 1e9 ;
    dp[0] = 0 ;
    rep(i,n){
        if(dp[i] == 1e9) continue ;
        int u = min(n+1,i+m+1) ;
        int v = segtree.query(i,u) ;
        if(dp[v] > dp[i] + 1){
            dp[v] = min(dp[v],dp[i]+1) ;
            pre[v] = i ;
        }
    }
    if(dp[n] == 1e9){
        cout << -1 << endl ;
        return 0 ;
    }
    int v = n ;
    while(v != 0){
        cout << v - pre[v] << " " ;
        v = pre[v] ;
    }
    cout << endl ;
}