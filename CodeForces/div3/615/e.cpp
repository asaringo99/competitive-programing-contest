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

// 座標圧縮
template<typename T=int> struct Compress{
    private:
        vector<int> vec ; // 元の値の座標圧縮後の値
        unordered_map<T,int> mp ; // 元の値 -> 変換された値
        unordered_map<int,T> np ; // 変換された値 -> 元の値
    public:
        Compress(vector<T> A){
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
        size_t size() {return vec.size() ; }
        // 元の値 -> 変換された値
        inline int encrypt(T i) { return mp[i] ; }
        // 変換された値 -> 元の値
        inline T decrypt(int i) { return np[i] ; }
        inline int operator [] (int i) { return vec[i] ; }
};

// function         : return              : description
// -----------------------------------------------------
// Compress(vector<ll> A) : void  : コンストラクタ, 座圧する
// encrypt(ll v)          : int   : 元の値 -> 座圧後の値
// decrypt(int v)         : ll    : 座圧後の値 -> 元の値
// operator[i]            : int   : 座圧後の値の vector にアクセスすることが可能

int n, m;

int main(){
    // fast_input_output
    cin >> n >> m;
    vector<vector<int>> A(m,vector<int>(n));
    rep(i,n) rep(j,m) cin >> A[j][i];
    int ans = 0;
    rep(i,m){
        vector<int> vec, arr(2*n);
        rep(j,2*n) vec.push_back(A[i][j%n]);
        rep(j,2*n) arr[j] = vec[j] - j * m;
        Compress C(arr);
        vector<int> K(2*n,0);
        rep(j,n) K[C[j]]++;
        int res = n;
        rep(j,n){
            if(vec[j] % m == (i + 1)%m && vec[j] <= n * m) {
                int pos = j * m;
                int val = vec[j] - (i + 1);
                pos -= val;
                int mod = m * n;
                (pos += m * n) %= mod;
                int mv = pos / m;
                chmin(res,n-K[C[j]]+mv);
            }
            int s = j+1;
            int k = j+n;
            K[C[j]]--;
            K[C[k]]++;
        }
        ans += res;
    }
    cout << ans << endl;
}