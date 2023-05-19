#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 1 << 18 ;

template<typename T>
struct SegmentTree{
    int n ;
    T dat[2 * MAX_N - 1] ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,-1,sizeof(dat)) ;
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
        if(r <= a || b <= l) return -1 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int w , n ;
ll dp[505][10007] ;

int main(){
    cin >> w >> n ;
    SegmentTree<ll> RMQ(w+1) ;
    memset(dp,-1,sizeof(dp)) ;
    dp[0][0] = 0 ;
    RMQ.update(0,0) ;
    for(int i = 0 ; i < n ; i++){
        int l , r , v ;
        cin >> l >> r >> v ;
        for(int j = 0 ; j <= w ; j++){
            dp[i+1][j] = dp[i][j] ;
            ll val = -1 ;
            if(j - r >= 0) val = RMQ.query(j-r,j-l+1) ;
            else if(j - l >= 0) val = RMQ.query(0,j-l+1) ;
            if(val != -1) {
                dp[i+1][j] = max(dp[i][j],val + v) ;
            }
        }
        for(int j = 0 ; j <= w ; j++) RMQ.update(j,dp[i+1][j]) ;
    }
    cout << dp[n][w] << endl ;
}