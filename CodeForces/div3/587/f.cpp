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

template <typename T>
struct LazySegmentTree{
    private :
        const ll linf = 1e18 ;
        const int inf = 1e8 ;
        int n , n_ ;

        vector<T> dat , lazy ;

        void build(){
            n = 1 ;
            while(n < n_) n *= 2 ;
            dat.resize(2*n-1,linf) ;
            lazy.resize(2*n-1,linf) ;
        }
        void eval(int k){
            if(lazy[k] == linf) return ;
            if(k < n - 1){
                chmin(lazy[2*k+1],lazy[k]) ;
                chmin(lazy[2*k+2],lazy[k]) ;
            }
            dat[k] = min(dat[k],lazy[k]) ;
            lazy[k] = linf ;
        }

        void update_(int a , int b , int k , int l , int r , T x){
            eval(k) ;
            if(r <= a || b <= l) return ;
            if(a <= l && r <= b) {
                lazy[k] = min(lazy[k],x) ;
                eval(k) ;
                return ;
            }
            update_(a,b,2*k+1,l,(l+r)/2,x) ;
            update_(a,b,2*k+2,(l+r)/2,r,x) ;
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }

        void update_(int a , int b , T x){
            update_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            eval(k) ;
            if(r <= a || b <= l) return linf ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return min(lef,rig) ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n) ;
        }

    public :
        LazySegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void update(int a , int b , T x) { update_(a,b,x) ; }
};

ll dp[202020];

void solve(){
    int n, k;
    string S;
    cin >> n >> k >> S;
    vector<int> A(n+1,0);
    rep(i,n) A[i+1] = S[i] - '0';
    LazySegmentTree<ll> lst(n+1);
    lst.update(0,1,0);
    rrep(i,1,n+1){
        if(A[i]){
            int l = max(1,i-k);
            int r = min(n,i+k);
            ll val = lst.query(l-1,l);
            lst.update(l,r+1,val+i);
        }
        else{
            ll val = lst.query(i-1,i);
            lst.update(i,i+1,val+i);
        }
    }
    cout << lst.query(n,n+1) << endl;
}

int main(){
    fast_input_output
    solve();
}