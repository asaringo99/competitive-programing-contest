#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

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
        fill(dat,dat+MAX_N,INF) ;
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
        dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
    }

    void update(int a , int b , int x){
        sub_updata(a,b,0,0,n,x) ;
    }

    T sub_query(int a , int b , int k , int l , int r){
        eval(k) ;
        if(r <= a || b <= l) return INF ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }

    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int main(){
    int  q ;
    cin >> n >> q ;
    LazySegTree<ll> LST(n) ;
    rep(i,q){
        int k , s , t , x ;
        cin >> k >> s >> t ;
        t++ ;
        if(k){
            cout << LST.query(s,t) << endl ;
        }
        else{
            cin >> x ;
            LST.update(s,t,x) ;
        }
    }
}