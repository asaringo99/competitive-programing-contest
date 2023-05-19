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

const int mod = 1000000007 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

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
        (dat[k] += x) % mod ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = (dat[2*k+1] + dat[2*k+2]) % mod ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return (lef + rig) % mod ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n ;

int main(){
    fast_input_output
    cin >> n ;
    SegmentTree<ll> up_lef(n) , up_rig(n) , down_lef(n) , down_rig(n) ;
    vector<P> A ;
    rep(i,n){
        int a ;
        cin >> a ;
        A.push_back(P(a,i)) ;
    }
    sort(A.begin(),A.end()) ;
    ll res = 0 ;
    int i = 0 ;
    while(i < n){
        auto [val,id] = A[n-1-i] ;
        vector<int> vec ;
        while(i < n && val == A[n-1-i].first){
            auto [v,k] = A[n-1-i] ;
            vec.push_back(k) ;
            ll rig = down_rig.query(k+1,n) ;
            ll lef = down_lef.query(0,k) ;
            res += rig * lef % mod ;
            res %= mod ;
            i++ ;
        }
        for(int u : vec){
            down_rig.add(u,powmod(2,n-1-u)) ;
            down_lef.add(u,powmod(2,u)) ;
        }
    }
    i = 0 ;
    while(i < n){
        auto [val,id] = A[i] ;
        vector<int> vec ;
        while(i < n && val == A[i].first){
            auto [v,k] = A[i] ;
            vec.push_back(k) ;
            ll rig = up_rig.query(k+1,n) ;
            ll lef = up_lef.query(0,k) ;
            res += rig * lef % mod ;
            res %= mod ;
            i++ ;
        }
        for(int u : vec){
            up_rig.add(u,powmod(2,n-1-u)) ;
            up_lef.add(u,powmod(2,u)) ;
        }
    }
    cout << res << endl ;
}