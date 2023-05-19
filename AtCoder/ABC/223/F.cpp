#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

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
        dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
    }
    void add(int a , int b , T x){
        return sub_add(a,b,0,0,n,x) ;
    }

    T sub_query(int a , int b , int k , int l , int r){
        //遅延評価（これは確実に必要）
        eval(k) ;
        if(b <= l || r <= a) return 1e9 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }

    T query(int a , int b){
        return sub_query(a,b,0,0,n)  ;
    }
};

int n , q ;
string S ;

int main(){
    cin >> n >> q ;
    cin >> S ;
    LazySegmentTree<ll> SegTree(n+2) ;
    int sum = 0 ;
    SegTree.add(0,1,sum) ;
    rep(i,n){
        if(S[i] == '('){
            sum++ ;
        }
        if(S[i] == ')'){
            sum-- ;
        }
        SegTree.add(i+1,i+2,sum) ;
    }
    // rep(i,n+1) cout << SegTree.query(i,i+1) << " " ;
    // cout << endl ;
    rep(i,q){
        int t , x , y ;
        cin >> t >> x >> y ;
        x-- ;
        if(t == 1){
            if(S[x] == S[y-1]) continue ;
            if(S[x] == '(') SegTree.add(x+1,y,-2) ;
            if(S[x] == ')') SegTree.add(x+1,y,2) ;
            swap(S[x],S[y-1]);
        }
        if(t == 2){
            // rep(j,n+1) cout << SegTree.query(j,j+1) << " " ;
            // cout << endl ;
            ll X = SegTree.query(x,x+1) , Y = SegTree.query(y,y+1) ;
            ll V = SegTree.query(x,y+1) ;
            // cout << X << " " << Y << " " << V << endl ;
            if(X == Y && V >= X) cout << "Yes" << endl ;
            else cout << "No" << endl ;
        }
    }
}