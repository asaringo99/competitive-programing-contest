#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , w ;

const int MAX_N = 1 << 19 ;
const int INF = INT_MAX ;

ll dat[2*MAX_N-1] ;
ll lazy[2*MAX_N-1] ;

template <typename T>
struct LazySegTree{
    int n ;
    LazySegTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,0,sizeof(dat)) ;
        fill(lazy,lazy+MAX_N,INF) ;
    }
    void eval(int k){
        if(lazy[k] == INF) return ;
        if(k < n - 1){
            lazy[2*k+1] = lazy[k] ;
            lazy[2*k+2] = lazy[k] ;
        }
        dat[k] = lazy[k] ;
        lazy[k] = INF ;
    }

    void sub_updata(int a , int b , int k , int l , int r , T x){
        eval(k) ;
        if(r <= a || b <= l) return ;
        if(a <= l && r <= b) {
            lazy[k] = x ;
            eval(k) ;
            return ;
        }
        sub_updata(a,b,2*k+1,l,(l+r)/2,x) ;
        sub_updata(a,b,2*k+2,(l+r)/2,r,x) ;
        dat[k] = max(dat[2*k+1],dat[2*k+2]) ;
    }

    void update(int a , int b , int x){
        sub_updata(a,b,0,0,n,x) ;
    }

    T sub_query(int a , int b , int k , int l , int r){
        eval(k) ;
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

int main(){
    cin >> w >> n ;
    LazySegTree<ll> LST(w+1) ;
    rep(i,n){
        int l , r ;
        cin >> l >> r ;
        l-- ;
        ll val = LST.query(l,r) ;
        LST.update(l,r,val+1) ;
        cout << val + 1 << endl ;
    }
}