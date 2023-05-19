#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
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

P A[202020],B[202020];

int main(){
    cin>> n >> m ;
    rep(i,m){
        ll a , b ;
        cin >> a >> b;
        a-- ; b-- ;
        A[i] = P(a,-b) ;
        B[i] = P(b,-a) ;
    }

    sort(A,A+m) ;
    sort(B,B+m) ;
    int res = 0 ;
    SegmentTree<ll> SegTree(n) ;
    rep(i,m){
        int x = A[i].first ;
        int y = A[i].second ;
        y = -y ;
        int tmp = SegTree.query(0,y) ;
        int val = SegTree.query(y,y+1) ;
        tmp++ ;
        tmp = max(tmp,val) ;
        SegTree.update(y,tmp) ;
        res = max(res,tmp) ;
    }
    cout << res << endl ;
}