#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

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
};

int n , q ;
string S ;

int main(){
    cin >> n >> q >> S ;
    SegmentTree<ll> segtree(n) ;
    rrep(i,1,n) if(S[i-1] == '(' && S[i] == ')') segtree.update(i,1) ;
    rep(i,q){
        int t , l , r ;
        cin >> t >> l ;
        l-- ;
        if(t == 1){
            if(S[l] == '('){
                if(l > 0 && S[l-1] == '(') segtree.update(l,1) ;
                if(l<n-1 && S[l+1] == ')') segtree.update(l+1,0) ;
                S[l] = ')' ;
            }
            if(S[l] == ')'){
                segtree.update(l,0) ;
                if(l < n - 1 && S[l+1] == ')') segtree.update(l+1,1) ;
                S[l] = '(' ;
            }
        }
        if(t == 2){
            cin >> r ;
            cout << segtree.query(l,r) << endl ;
        }
    }
}