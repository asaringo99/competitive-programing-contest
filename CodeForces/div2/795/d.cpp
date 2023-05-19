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

template<typename T = long long> struct SegmentTree{
    int n , n_;
    vector<T> dat ;
    vector<pair<int,int>> range;
    SegmentTree(int _n){
        n = 1;
        n_ = _n;
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
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 1e18 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
    T binary_search(int k , T x){
        int m = 2 * n - 1;
        k += n - 1;
        T res = dat[k];
        if(res <= x) return range[k].second;
        while(true){
            if(k % 2 == 1){
                if( min(res, dat[k+1]) > x ){
                    k++;
                    res = min(res,dat[k]);
                }
                else if(2*k+1>=2*n-1) break;
                else if( min(res, dat[2*k+3]) > x ){
                    m = m * 2 + 1;
                    k = 2 * k + 3;
                    res = min(res,dat[k]);
                }
                else {
                    m = m * 2 + 1;
                    k = 2 * k + 2;
                }
            }
            else{
                if(k + 1 == m) break;
                if( min(res, dat[(k-1)/2+1]) > x ){
                    m /= 2;
                    k = (k - 1) / 2 + 1;
                    res = min(res,dat[k]);
                }
                else if( min(res,dat[k+1]) > x ){
                    k++;
                    res = min(res,dat[k]);
                }
                else if(2*k+1>=2*n-1) break;
                else if( min(res,dat[2*k+3]) > x ){
                    m = m * 2 + 1;
                    k = 2 * k + 3;
                    res = min(res,dat[k]);
                }
                else{
                    m = m * 2 + 1;
                    k = 2 * k + 2;
                }
            }
        }
        return range[k].second+1;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<ll> A(n), S(n+1), T(n+1);
    SegmentTree<ll> s(n+1), t(n+1);
    vector<pair<int,int>> vec;
    rep(i,n) {
        cin >> A[i];
        if(A[i] > 0) vec.push_back({A[i],i});
    }
    rep(i,n){
        S[i+1] = S[i] + A[i];
        s.add(i+1,S[i+1]);
    }
    rep(i,n){
        T[i+1] = T[i] + A[n-1-i];
        t.add(i+1,T[i+1]);
    }
    bool ok = true;
    set<int> st;
    st.insert(-1);
    st.insert(n);
    sort(vec.begin(),vec.end(),greater<pair<int,int>>());
    for(auto p : vec){
        auto[x,id] = p;
        st.insert(id);
        if(id < n - 1){
            auto rt = st.upper_bound(id);
            int r = *rt;
            ll rig = T[n-id] - t.query(n-r,n-id);
            if(rig > A[id]) ok = false;
        }
        if(id > 0){
            auto lt = st.lower_bound(id); lt--;
            int l = *lt;
            ll lef = S[id+1] - s.query(l+1,id+1);
            if(lef > A[id]) ok = false;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve();
}