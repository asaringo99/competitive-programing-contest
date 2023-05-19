#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
    int n , n_;
    vector<T> dat ;
    SegmentTree(int _n){
        n = 1 ;
        n_ = _n ;
        while(n < _n) n *= 2 ;
        dat.resize(2 * n - 1,0) ;
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
        if(r <= a || b <= l) return -1e9 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n ;
int X[202020] ;
int S[202020] , T[202020] ;
int res[202020] ;
map<int,int> mp ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n){
        int x , y ;
        cin >> x >> y ;
        x-- ; y-- ;
        X[x] = y ;
        mp[x] = i ;
    }
    SegmentTree<int> seg_s(n) , seg_t(n) ;
    for(int i = n - 1 ; i >= 0 ;i--){
        int y = X[i] ;
        int val = seg_s.query(y,n) ;
        S[i] = val + 1 ;
        seg_s.update(y,S[i]) ;
    }
    for(int i = 0 ; i < n ;i++){
        int y = X[i] ;
        int val = seg_t.query(0,y+1) ;
        T[i] = val + 1 ;
        seg_t.update(y,T[i]) ;
    }
    rep(i,n){
        res[mp[i]] = max(S[i],T[i]) ;
    }
    rep(i,n) cout << res[i] << endl ;
}