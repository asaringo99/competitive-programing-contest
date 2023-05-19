#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

const int MAX_N = 1 << 19 ;
ll dat[2 * MAX_N - 1] , lazy[2 * MAX_N - 1] ;

template<typename T>
struct LazySegmentTree{
    int n ;
    LazySegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,0,sizeof(dat)) ;
        memset(lazy,0,sizeof(lazy)) ;
    }

    // 遅延評価
    void eval(int k){
        dat[k] += lazy[k] ;
        if(k < n - 1){
            lazy[2 * k + 1] += lazy[k] ;
            lazy[2 * k + 2] += lazy[k] ;
        }
        lazy[k] = 0 ;
    }

    // 区間加算
    void sub_add(int a , int b , int k , int  l , int r , T w){
        eval(k) ;
        if(b <= l || r <= a) return ;
        if(a <= l && r <= b) {
            // 区間加算
            lazy[k] += w ;
            eval(k) ;
            return ;
        }
        sub_add(a,b,2*k+1,l,(l+r)/2,w) ;
        sub_add(a,b,2*k+2,(l+r)/2,r,w) ;
        // 区間の更新をする必要がある
        dat[k] = max(dat[2*k+1],dat[2*k+2]) ;
    }
    void add(int a , int b , T x){
        return sub_add(a,b,0,0,n,x) ;
    }

    T sub_query(int a , int b , int k , int l , int r){
        //遅延評価（これは確実に必要）
        eval(k) ;
        if(b <= l || r <= a) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }

    T query(int a , int b){
        return sub_query(a,b,0,0,n)  ;
    }
};

vector<P> query[200007] ;

int main(){
    int q ;
    cin >> n >> q ;
    LazySegmentTree<ll> LST(200007) ;
    rep(i,q){
        ll l , r , v ;
        cin >> l >> r >> v ;
        query[r].push_back(P(l,v)) ;
    }
    rep(i,200005){
        ll val = LST.query(0,i) ;
        LST.add(i,i+1,val) ;
        for(P p : query[i]){
            ll l = p.first , v = p.second ;
            LST.add(l,i+1,v) ;
        }
    }
    cout << LST.query(0,200005) << endl ;
}