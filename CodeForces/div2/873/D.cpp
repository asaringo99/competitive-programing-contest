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

// 座標圧縮
template<typename T=int> struct Compress{
    private:
        vector<int> vec ; // 元の値の座標圧縮後の値
        unordered_map<T,int> mp ; // 元の値 -> 変換された値
        unordered_map<int,T> np ; // 変換された値 -> 元の値

        void build(vector<T> A){
            int n = A.size() ;
            vector<T> B(n) ;
            for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
            vec.resize(n) ;
            sort(A.begin(),A.end()) ;
            for(int i = 0 ; i < n ; i++){
                auto it = lower_bound(A.begin(),A.end(),B[i]) ;
                int id = it - A.begin() ;
                vec[i] = id ;
                mp[B[i]] = id;
                np[id] = B[i] ;
            }
        }

    public:
        Compress(){}
        Compress(vector<T> A) { build(A); }
        size_t size() {return vec.size() ; }
        // 元の値 -> 変換された値
        inline int encrypt(T i) { return mp[i] ; }
        // 変換された値 -> 元の値
        inline T decrypt(int i) { return np[i] ; }
        vector<int> compress() { return vec; }
        vector<int> compress(vector<T> A) { build(A); return vec; }
        inline int operator [] (int i) { return vec[i] ; }
};

// function               : return              : description
// -----------------------------------------------------
// Compress()             : void          : コンストラクタ
// Compress(vector<ll> A) : void          : コンストラクタ, 座圧する
// encrypt(ll v)          : int           : 元の値 -> 座圧後の値
// decrypt(int v)         : ll            : 座圧後の値 -> 元の値
// compress()             : vector<int>   : 座圧後の値
// operator[i]            : int           : 座圧後の値の vector にアクセスすることが可能

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
    T binary_search(int k , T x){
        k += n - 1;
        int cnt = 1, m = 2 * n - 1;
        T val = dat[k], res = 0;
        while(k > 0 && res + val < x){
            cnt *= 2;
            m /= 2;
            if((k-1)/2*2+1 == k){
                k = (k - 1) / 2;
                val = dat[k];
            }
            else{
                if((k - 1) / 2 + 1 >= m) break;
                k = (k - 1) / 2;
                k++;
                res += val;
                val = dat[k];
            }
        }
        res += val;
        if(res < x) return n;
        while(true){
            m *= 2;
            m++;
            if(2*k+1>2*n-1) break;
            if(res - dat[2*k+2] >= x){
                res -= dat[2*k+2];
                k = 2 * k + 1;
            }
            else{
                k = k * 2 + 2;
            }
        }
        return range[k].second;
    }
};

void solve(){
    int n, t;
    cin >> n;
    vector<ll> A(n);
    set<pair<int,int>> st;
    set<ll> tt;
    rep(i,n) cin >> A[i];
    Compress C(A);
    rep(i,n) tt.insert(C[i]);
    SegmentTree<ll> segtree(n);
    rep(i,n) segtree.add(C[i],1);
    ll res = 0;
    ll sum = 0;
    rep(i,n-1){
        tt.erase(C[i]);
        st.insert({C[i],i});
        segtree.add(C[i],-1);
        for(auto [u, id] : st){
            cout << u << " " << segtree.query(0,u) << endl;
            res += segtree.query(0,u);
        }
        cout << res << endl;
    }
    cout << res << endl;
    // vector<S> vec(n);
    // rep(i,n) vec[i] = {A[i]};
    // SegmentTree<S, op, mapping, e> segtree(vec);
    // // rep(i,n-1) cout << segtree.prod(i,i+2).min << " "; cout << endl;
    // rep(i,n){
    //     target = A[i];
    //     // cout << target << endl;
    //     int r = segtree.max_right<f>(i);
    //     r--;

    // }
}

int main(){
    // fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}