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

int n;

vector<int> X;
multiset<ld> mst[7];
ld dp[202020];
ld ep[202020];
int mp[202020];
int cnt[202020];

int main(){
    fast_io
    cin >> n;
    vector<vector<ll>> A(n,vector<ll>(6));
    rep(i,n) rep(j,6) cin >> A[i][j], X.push_back(A[i][j]);
    Compress C(X);
    rep(i,n) rep(j,6) A[i][j] = C.encrypt(A[i][j]);
    rep(i,n) rep(j,6) mp[A[i][j]] = i;
    dp[6*n-1] = 1;
    ep[mp[6*n-1]] = 1;
    rep(i,n-1) mst[0].insert(0);
    cnt[mp[6*n-1]] = 1;
    mst[1].insert(1);
    for(int i = n * 6 - 2; i >= 0; i--){
        ld res = 0;
        rrep(i,1,7){
            if(mst[i].empty()) continue;
            auto it = mst[i].end(); it--;
            ld val = *it;
            chmax(res, (ld)1/6 * val);
        }
        dp[i] = res + 1;
        auto it = mst[cnt[mp[i]]].lower_bound(ep[mp[i]]-0.000000000001);
        mst[cnt[mp[i]]].erase(it);
        cnt[mp[i]]++;
        ep[mp[i]] += dp[i];
        // cout << dp[i] << " " << mp[i] << " " << ep[mp[i]] << " " << cnt[mp[i]] << endl;
        mst[cnt[mp[i]]].insert(ep[mp[i]]);
    }
    auto it = mst[6].end(); it--;
    ld res = *it / 6 + 1;
    cout << fixed << setprecision(25) << res << endl;
}