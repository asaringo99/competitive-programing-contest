#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
P X[202020] ;

struct SegTree{
    int n ;
    ll up[2 * (1 << 20)] , down[2 * (1 << 20)] ;
    SegTree(int n_){
        memset(up,0,sizeof(up)) ;
        memset(down,0,sizeof(down)) ;
        n = 1 ;
        while(n < n_) n *= 2 ;
        for(int i = 0 ; i < n ; i++){
            up[i + n - 1] = -1e18 ;
            down[i + n - 1] = 1e18 ;
        }
        for(int i = 0 ; i < n_ ; i++){
            up[i + n - 1] = X[i].second ;
            down[i + n - 1] = X[i].second ;
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            up[i] = max(up[2*i+1],up[2*i+2]) ;
            down[i] = min(down[2*i+1],down[2*i+2]) ;
        }
    }
    ll sub_query_up(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return -1e18 ;
        if(a <= l && r <= b) return up[k] ;
        ll lef = sub_query_up(a,b,2*k+1,l,(l+r)/2) ;
        ll rig = sub_query_up(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }
    ll sub_query_down(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 1e18 ;
        if(a <= l && r <= b) return down[k] ;
        ll lef = sub_query_down(a,b,2*k+1,l,(l+r)/2) ;
        ll rig = sub_query_down(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }
    ll query_up(int a , int b){ return sub_query_up(a,b,0,0,n) ; }
    ll query_down(int a , int b){ return sub_query_down(a,b,0,0,n) ; }
} ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i].first >> X[i].second ;
    sort(X,X+n) ;
    SegTree up(n) , down(n) ;
    ll lef = 0 , rig = 1e10 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        bool ok = false ;
        rep(i,n){
            int x = X[i].first , y = X[i].second ;
            auto it = lower_bound(X,X+n,P(x+mid,-1)) ;
            int id = it - X ;
            if(id == n) break ;
            ll u = up.query_up(id,n) ;
            ll d = down.query_down(id,n) ;
            ll val = max(u-y,y-d) ;
            if(val >= mid) ok = true ;
        }
        if(ok) lef = mid ;
        else rig = mid ;
    }
    cout << lef << endl ;
}