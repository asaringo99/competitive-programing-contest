#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct SegmentTree{
    int n ;
    ll dat[1 << 21] ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,0,sizeof(dat)) ;
    }
    void add(int k , int x){
        k += n - 1 ;
        dat[k] += x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }
    }
    ll sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 1e8 ;
        if(a <= l && r <= b) return dat[k] ;
        ll lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        ll rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }
    ll query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n , m ;
P X[101010] ;
int S[303030] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a, b ;
        cin >> a >> b ;
        a-- ;
        S[a]++ ;
        S[b]-- ;
        X[i] = P(a,b) ;
    }
    SegmentTree segtree(n+1) ;
    int s = 0 ;
    rep(i,n+1){
        s += S[i] ;
        segtree.add(i,s) ;
    }
    vector<int> res ;
    rep(i,m){
        if(segtree.query(X[i].first,X[i].second) > 1) res.push_back(i+1) ;
    }
    cout << res.size() << endl ;
    for(int u : res) cout << u << endl ;
}