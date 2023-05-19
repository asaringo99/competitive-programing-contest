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
        for(int i = 0; i < n_ ; i++) dat[i + n - 1]++ ;
        for(int i = n - 2 ; i >= 0 ; i--) dat[i] = dat[2*i+1] + dat[2*i+2] ;
    }
    void update(int k , ll x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
    }
    ll sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        ll lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        ll rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return lef + rig ;
    }
    ll query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
    ll lower_bound(ll x){
        int lef = 0 , rig = n ;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2 ;
            if(query(0,mid) < x) lef = mid ;
            else rig = mid ;
        }
        return rig ;
    }
};

ll n , k ;

int main(){
    cin >> n >> k ;
    SegmentTree segtree(n) ;

    ll v = 1 , m = n ;
    rep(i,n){
        v *= m ;
        ll t = v / k ;
        if(v % k == 0) {
            ll s = segtree.lower_bound(t) ;
            cout << s << endl ;
            segtree.update(s-1,0) ;
            break ;
        }
        ll s = segtree.lower_bound(t+1) ;
        cout << s << endl ;
        segtree.update(s-1,0) ;
        v -= t * k ;
        m-- ;
    }
    for(int i = n - 1 ; i >= 0 ; i--) if(segtree.query(i,i+1) > 0) cout << i + 1  << endl ;
}