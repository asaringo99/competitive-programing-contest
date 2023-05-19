#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

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
    T binary_search(int a , T k){
        int lef = a , rig = n_ ;
        while(rig - lef > 1){
            int mid = (lef + rig) / 2 ;
            if(query(a,mid) >= k) rig = mid ;
            else lef = mid ;
        }
        return lef ;
    }
};

int n , m ;

TP A[202020];
set<int> st;

int main(){
    cin >> n >> m ;
    rep(i,m){
        ll l,r,x;
        cin >> l >> r >> x;
        l--; r--;
        A[i] = {r,l,x};
    }
    sort(A,A+m);
    rep(i,n) st.insert(i);
    SegmentTree<int> segtree(n);
    rep(i,m){
        auto[rig,lef,x] = A[i];
        int cnt = segtree.query(lef,rig+1) ;
        if(cnt >= x) continue;
        int y = x - cnt;
        auto it = st.upper_bound(rig); it--;
        while(y > 0){
            if(*it < lef) continue;
            segtree.add(*it,1);
            st.erase(it--);
            y--;
        }
    }
    rep(i,n){
        if(st.count(i) == 1) cout << 0 << endl;
        else cout << 1 << endl;
    }
}