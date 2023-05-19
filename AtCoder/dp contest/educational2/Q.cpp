#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 1 << 18 ;

int n ;
ll H[2 * MAX_N + 7] , A[2 * MAX_N + 7] , dat[2 * MAX_N + 7] ;
ll dp[202020] ;

struct SegTree{
    int n ;

    SegTree(int n_){
        memset(dat,0,sizeof(dat)) ;
        n = 1 ;
        while(n < n_) n *= 2 ;
    }

    void update(int k , ll x){
        k += n - 1 ;
        dat[k] += x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = max(dat[2*k+1],dat[2*k+2]) ;
        }
    }

    ll sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        ll lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        ll rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }

    ll query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }

};

int main(){
    cin >> n ;
    SegTree RQM(n + 1) ;
    rep(i,n) cin >> H[i] ;
    rep(i,n) cin >> A[i] ;
    rep(i,n){
        ll val = RQM.query(0,H[i]) ;
        dp[i] = val + A[i] ;
        RQM.update(H[i],dp[i]) ;
    }
    cout << RQM.query(0,n+1) << endl ;
}