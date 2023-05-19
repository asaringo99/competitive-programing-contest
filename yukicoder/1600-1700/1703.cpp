#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
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
    void add(int k , T x){
        k += n - 1 ;
        dat[k] += x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = max(dat[2*k+1],dat[2*k+2]) ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return -1e18 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
    T solve(){
        int lef = 0 , rig = n ;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2 ;
            if(query(lef,mid) <= query(mid,rig)) lef = mid ;
            else rig = mid ;
        }
        return lef ;
    }
};

ll n , m , q ;

ll A[101010] , B[101010] , C[101010] ;
unordered_map<int,int> mp ;

int main(){
    cin >> n >> m ;
    SegmentTree<ll> SegTree(202020) ;
    rep(i,m) cin >> A[i] ;
    rep(i,m) SegTree.add(i,A[i]) ;
    cin >> q ;
    int id = m ;
    rep(i,q){
        ll t , x , y ;
        cin >> t >> x >> y ;
        x-- ;
        if(x >= m){
            mp[id] = x ;
            mp[x] = id ;
            x = id ;
            id++ ;
        }
        if(t == 1){
            SegTree.add(x,y) ;
        }
        if(t == 2){
            SegTree.add(x,-y) ;
        }
        if(t == 3){
            ll res = SegTree.solve() ;
            if(res >= m) res = mp[res] ;
            else res++ ;
            cout << res << endl ;
        }
    }
}