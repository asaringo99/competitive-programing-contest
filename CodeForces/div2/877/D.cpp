#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename T>
struct SegmentTree{
    private :
        const ll linf = 1e18 ;
        const int inf = 1e8 ;

        int n , n_ ;
        vector<T> dat , lazy ;

        void build(){
            n = 1 ;
            while(n < n_) n *= 2 ;
            dat.resize(2*n-1,0) ;
            lazy.resize(2*n-1,0) ;
        }

        // 遅延評価
        void eval(int k){
            dat[k] += lazy[k] ;
            if(k < n - 1){
                lazy[2 * k + 1] += lazy[k] / 2 ;
                lazy[2 * k + 2] += lazy[k] / 2 ;
            }
            lazy[k] = 0 ;
        }

        // 区間加算
        void add_(int a , int b , int k , int  l , int r , T w){
            eval(k) ;
            if(b <= l || r <= a) return ;
            if(a <= l && r <= b) {
                // 区間加算
                lazy[k] += (r - l) * w ;
                eval(k) ;
                return ;
            }
            add_(a,b,2*k+1,l,(l+r)/2,w) ;
            add_(a,b,2*k+2,(l+r)/2,r,w) ;
            // 区間の更新をする必要がある
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
        void add_(int a , int b , T x){
            return add_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            //遅延評価（これは確実に必要）
            eval(k) ;
            if(b <= l || r <= a) return 0 ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return lef + rig ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n)  ;
        }

    public :
        SegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void add(int a , int b , T x) { add_(a,b,x) ; }
};

template<typename T>
struct LazySegmentTree{
    private :
        const ll linf = 1e18 ;
        const int inf = 1e8 ;

        int n , n_ ;
        vector<T> dat , lazy ;

        void build(){
            n = 1 ;
            while(n < n_) n *= 2 ;
            dat.resize(2*n-1,0) ;
            lazy.resize(2*n-1,0) ;
        }

        // 遅延評価
        void eval(int k){
            dat[k] += lazy[k] ;
            if(k < n - 1){
                lazy[2 * k + 1] += lazy[k] ;
                lazy[2 * k + 2] += lazy[k] ;
            }
            lazy[k] = 0 ;
        }

        // 区間加算
        void add_(int a , int b , int k , int  l , int r , T w){
            eval(k) ;
            if(b <= l || r <= a) return ;
            if(a <= l && r <= b) {
                // 区間加算
                lazy[k] += w ;
                eval(k) ;
                return ;
            }
            add_(a,b,2*k+1,l,(l+r)/2,w) ;
            add_(a,b,2*k+2,(l+r)/2,r,w) ;
            // 区間の更新をする必要がある
            dat[k] = min(dat[2*k+1],dat[2*k+2]) ;
        }
        void add_(int a , int b , T x){
            return add_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            //遅延評価（これは確実に必要）
            eval(k) ;
            if(b <= l || r <= a) return inf ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return min(lef,rig) ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n)  ;
        }
    
    public :
        LazySegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void add(int a , int b , T x) { add_(a,b,x) ; }
};

void solve(){
    int n, q;
    cin >> n >> q;
    LazySegmentTree<int> segtree(n);
    SegmentTree<int> maxtree(n);
    string S;
    cin >> S;
    set<int> L, R;
    L.insert(n);
    R.insert(-1);
    rep(i,n-1){
        if(S[i] == S[i+1] && S[i] == '(') L.insert(i);
    }
    for(int i = n - 1; i > 0; i--){
        if(S[i] == S[i-1] && S[i] == ')') R.insert(i);
    }
    rep(i,n){
        if(S[i] == '(') segtree.add(i,i+1,1), maxtree.add(i,i+1,1);
        if(S[i] == ')') segtree.add(i,i+1,-1), maxtree.add(i,i+1,-1);
    }
    int cnt_l = 0;
    int cnt_r = 0;
    rep(i,n){
        if(S[i] == '(') cnt_l++;
        if(S[i] == ')') cnt_r++;
    }
    rep(i,q){
        int p;
        cin >> p;
        p--;
        if(p < n - 1){
            if(S[p] == ')' && S[p] == S[p+1]) R.erase(p+1);
            if(S[p] == ')' && S[p] != S[p+1]) L.insert(p);
            if(S[p] == '(' && S[p] == S[p+1]) L.erase(p);
            if(S[p] == '(' && S[p] != S[p+1]) R.insert(p+1);
        }
        if(p > 0){
            if(S[p] == ')' && S[p] == S[p-1]) R.erase(p);
            if(S[p] == ')' && S[p] != S[p-1]) L.insert(p-1);
            if(S[p] == '(' && S[p] == S[p-1]) L.erase(p-1);
            if(S[p] == '(' && S[p] != S[p-1]) R.insert(p);
        }
        if(S[p] == '(') S[p] = ')';
        if(S[p] == ')') S[p] = '(';
        if(S[p] == '(') segtree.add(p,n,2), maxtree.add(p,n,2);
        if(S[p] == ')') segtree.add(p,n,-2), maxtree.add(p,n,-2);
        if(S[p] == '(') cnt_l++, cnt_r--;
        if(S[p] == ')') cnt_l--, cnt_r++;
        if(cnt_l % 2 != cnt_r % 2){
            cout << "NO" << endl ;
            continue;
        }
        int segval = segtree.query(0,n);
        auto it = L.begin();
        auto jt = R.end(); jt--;
        int lid = *it;
        int rid = *jt; rid++;
        if(lid == n && rid == -1){
            if(segval == 0) cout << "YES" << endl;
            else cout << "NO" << endl ;
            continue;
        }
        if(segtree.query(0,lid) < 0 || maxtree.query(rid,n) != 0){
            cout << "NO" << endl ;
        }
        else cout << "YES" << endl ;
        // if(lid > rid){
        //     cout << "NO" << endl ;
        //     continue;
        // }
        // cout << lid << " " << rid << endl;
        // auto itl = L.lower_bound(rid);
        // auto itr = R.lower_bound(0);
        // if(*itl == n && *itr >= lid){
        //     cout << "YES" << endl ;
        // }
        // else cout << "NO" << endl ;
    }
}

int main(){
    fast_io
    solve();
}