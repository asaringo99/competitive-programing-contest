#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define ptv(v) for(auto u : v) cout << u << " "; cout << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename T = long long>
struct SegmentTree{
    int n , n_;
    vector<T> dat;
    vector<pair<int,int>> range;
    SegmentTree(int _n){
        n = 1 ;
        n_ = _n ;
        while(n < _n) n *= 2;
        dat.resize(2 * n - 1,0);
        range.resize(2 * n - 1);
        range[0] = {0,n};
        for(int i = 0 ; i < n - 1 ; i++){
            auto [l,r] = range[i];
            range[2*i+1] = {l,l+(r-l)/2};
            range[2*i+2] = {l+(r-l)/2,r};
        }
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


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> A(n,vector<ll>(m));
    rep(i,n) rep(j,m) cin >> A[i][j];
    vector<pair<ll,int>> S;
    rep(i,n) rep(j,m){
        S.push_back({A[i][j],i});
    }
    sort(all(S));
    SegmentTree<ll> segtree(n);
    rep(i,n) segtree.add(i,1);
    ll res = 0;
    for(auto[v,id] : S){
        // cout << v << " " << id << endl;
        res += segtree.query(id+1,n);
        res += (segtree.query(id,id+1) - 1) * (n - id - 1);
        segtree.add(id,1);
    }
    cout << res << endl;
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}