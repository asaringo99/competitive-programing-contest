#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct SegmentTree{
    int n ;
    ll dat[303030] ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        for(int i = 0 ; i < 2 * n - 1 ; i++) dat[i] = 1e14 ;
        update(0,0) ;
    }

    void update(int k , ll x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }
    }

    ll sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 1e14 ;
        if(a <= l && r <= b) return dat[k] ;
        ll lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        ll rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }

    ll query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
} ;

int n , l ;
TP X[101010] ;
ll dp[101010] ;

int main(){
    cin >> n >> l ;
    SegmentTree SegTree(l+1) ;
    rep(i,n){
        int a , b , c ;
        cin >> a >> b >> c ;
        X[i] = {a,b,c} ;
    }
    sort(X,X+n) ;
    rep(i,l+1) dp[i] = 1e14 ;
    dp[0] = 0 ;
    rep(i,n){
        ll a , b , c ;
        tie(a,b,c) = X[i] ;
        ll val = SegTree.query(a,b+1) ;
        if(dp[b] > val + c){
            dp[b] = val + c ;
            SegTree.update(b,val+c) ;
        }
    }
    cout << dp[l] << endl ;
}