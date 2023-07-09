#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll;
typedef long double ld;
#define chmin(a,b) a = min(a,b);
#define chmax(a,b) a = max(a,b);
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl;
#define debug(a) cout << #a << " " << a << endl;
#define all(a) a.begin(), a.end()
#define endl "\n";
#define v1(n,a) vector<ll>(n,a)
#define v2(n,m,a) vector<vector<ll>>(n,v1(m,a))
#define v3(n,m,k,a) vector<vector<vector<ll>>>(n,v2(m,k,a))
#define v4(n,m,k,l,a) vector<vector<vector<vector<ll>>>>(n,v3(m,k,l,a))
template<typename T,typename U>istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T,typename U>ostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T>istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>istream &operator>>(istream&is,vector<vector<T>>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<vector<T>>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?"\n":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const set<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const multiset<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}

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

template<typename T>
struct SegmentTree{
    int n , n_;
    vector<T> dat ;
    SegmentTree(int _n){
        n = 1 ;
        n_ = _n ;
        while(n < _n) n *= 2 ;
        dat.resize(2 * n - 1,1e18) ;
    }
    void update(int k , T x){
        k += n - 1 ;
        chmin(dat[k],x) ;
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
};


void solve(){
    int n;
    cin >> n;
    vector<vector<ll>> X(n);
    rep(i,n){
        ll h, w, d;
        cin >> h >> w >> d;
        vector<ll> V = {h,w,d};
        sort(all(V));
        X[i] = V;
    }
    sort(all(X));
    vector<ll> A(n), B(n), Z(n);
    rep(i,n){
        auto V = X[i];
        // pt(V);
        Z[i] = V[0];
        A[i] = V[1];
        B[i] = V[2];
    }
    Compress C(A), D(B);
    SegmentTree<ll> segtree(n);
    queue<pair<int,int>> que;
    ll bef = Z[0];
    rep(i,n){
        int z = Z[i];
        int c = C[i];
        int d = D[i];
        ll value = segtree.query(0,c);
        // rep(i,n) cout << segtree.query(i,i+1) << " " ; cout << endl;
        // cout << z << " " << c << " " << d << " " << value << endl;
        if(value < d){
            cout << "Yes" << endl ;
            return;
        }
        que.push({c,d});
        if((i < n - 1 && Z[i+1] != z) || (i == n - 1)){
            while(!que.empty()){
                auto [s,t] = que.front(); que.pop();
                segtree.update(s,t);
            }
        }
        bef = z;
    }
    cout << "No" << endl ;
}

int main(){
    fast_io
    int t = 1;
    // cin >> t;
    rep(i,t) solve();
}