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
#define input(a) cin >> a
#define print(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl

const int mod = 1000000007 ;

template<typename T>
struct SegmentTree{
    int n , n_;
    vector<T> dat ;
    SegmentTree(int _n){
        n_ = _n ;
        n = 1 ;
        while(n < _n) n *= 2 ;
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
};

int zzz ;
int n ;
vector<int> A ;

void solve(){
    cin >> n ;
    A.resize(n) ;
    rep(i,n) cin >> A[i] ;
    vector<P> B ;
    rep(i,n) B.push_back(P(A[i],i)) ;
    sort(B.begin(),B.end()) ;
    SegmentTree<int> segtree(n) ;
    ll res = 1 ;
    ll lef = 1e9 , rig = 0 ;
    rep(i,n){
        auto [b,id] = B[i] ;
        if(lef < id && id < rig) res *= (rig - lef - 1) - segtree.query(lef+1,rig) ;
        res %= mod ;
        chmin(lef,id) ;
        chmax(rig,id) ;
        segtree.add(id,1) ;
    }
    cout << res << endl ;
}

int main(){
    fast_input_output
    cin >> zzz ;
    rep(i,zzz) solve() ;
}