#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

const int MAX_N = 1 << 18 ;

ll dat[2*MAX_N-1] ;
ll A[MAX_N] , H[MAX_N] ;

struct RQM{
    int n ;
    RQM(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,0,sizeof(dat)) ;
    }
    void change(int v , ll x){
        v += n - 1 ;
        dat[v] = x ;
        while(v > 0){
            v = (v - 1) / 2 ;
            dat[v] = max(dat[2*v+1],dat[2*v+2]) ;
        }
    }
    ll sub_get(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        ll lef = sub_get(a,b,2*k+1,l,(l+r)/2) ;
        ll rig = sub_get(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }
    ll get(int a , int b){
        return sub_get(a,b,0,0,n) ;
    }
};

// educational contest Q
int main(){
    cin >> n ;
    RQM segtree(n) ;
    rep(i,n) cin >> H[i] ;
    rep(i,n) cin >> A[i] ;
    ll res = 0 ;
    rep(i,n){
        ll val = segtree.get(0,H[i]) ;
        segtree.change(H[i]-1,val+A[i]) ;
        res = max(res,val+A[i]) ;
    }
    cout << res << endl ;
}