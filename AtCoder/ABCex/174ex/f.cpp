#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

template<typename T>
struct SegmentTree{
    int n ;
    vector<T> dat ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        dat.resize(2 * n - 1,0) ;
    }
    void add(int k , T x){
        k += n - 1 ;
        dat[k] += x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return lef + rig ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
    T binary_search(int k){
        ll lef = 0 , rig = n ;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2 ;
            if(query(0,mid) < k) lef = mid ;
            else rig = mid ;
        }
        return rig ;
    }
};

int n , q ;
vector<int> A[505050] ;
vector<P> query[505050] ;
vector<int> vec[505050] ;
int res[505050] ;

int main(){
    cin >> n >> q ;
    SegmentTree<ll> segtree(n) ;
    rep(i,n){
        int a ;
        cin >> a ;
        a-- ;
        A[a].push_back(i) ;
    }
    rep(i,505050){
        for(int j = 0 ; j < (int)A[i].size() - 1 ; j++){
            vec[A[i][j]].push_back(A[i][j+1]) ;
        }
    }
    rep(i,q){
        int l , r ;
        cin >> l >> r ;
        l-- ; r-- ;
        query[l].push_back(P(r,i)) ;
    }
    for(int i = 500000 ; i >= 0 ; i--){
        for(int u : vec[i]){
            segtree.add(u,1) ;
        }
        for(P p : query[i]){
            int u = p.first , id = p.second ;
            int v = segtree.query(i,u+1) ;
            res[id] = u - i + 1 - v ;
        }
    }
    rep(i,q) cout << res[i] << endl ;
}