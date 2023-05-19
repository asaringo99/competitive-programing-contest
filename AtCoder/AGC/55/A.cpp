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
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename T>
struct RunLengthCompression {
    private:
        vector<pair<T,int>> res ;
        vector<T> A_ , A ;
        int n ;
        void build_(){
            A.resize(n+1) ;
            for(int i = 0 ; i < n ; i++) A[i] = A_[i] ;
            int cnt = 1 ;
            for(int i = 0 ; i < n ; i++){
                if(A[i] == A[i+1]) cnt++ ;
                else{
                    res.push_back(pair<T,int>(A[i],cnt)) ;
                    cnt = 1 ;
                }
            }
        }
    public:
        RunLengthCompression(vector<T> _A): A_(_A), n(_A.size()) {} ;
        void build() { build_() ; }
        vector<pair<T,int>> get_RLC() { return res ; }
};

// ----------------------------
// function                           : return              : description
// -----------------------------------------------------
// RunLengthCompression(vector<T> _A) :                     : コンストラクタ
// build()                            : void                : ビルドする（必ず行うこと）
// get_RLC()                          : vector<pair<T,int>> : ランレングス圧縮の結果を返す
// ----------------------------
// *注意*
// ----------------------------
// build をちゃんと行うこと

int n, q;

int main(){
    fast_input_output
    cin >> n >> q;
    vector<char> S(n);
    rep(i,n) cin >> S[i];
    RunLengthCompression<char> RLC(S);
    RLC.build();
    auto vec = RLC.get_RLC();
    vector<int> T(n);
    vector<char> X;
    int cnt = 0;
    rep(i,vec.size()){
        auto[c, id] = vec[i];
        rrep(j,cnt,cnt+id) T[j] = i;
        cnt += id;
        X.push_back(c);
    }
    int m = vec.size();
    vector<int> A(m+1,0);
    vector<int> B(m+1,0);
    vector<int> C(m+1,0);
    rep(i,m){
        A[i+1] = A[i];
        B[i+1] = B[i];
        C[i+1] = C[i];
        if(X[i] == 'A') A[i+1]++;
        if(X[i] == 'B') B[i+1]++;
        if(X[i] == 'C') C[i+1]++;
    }
    rep(i,q){
        int a, b;
        cin >> a >> b;
        a--; b--;
        a = T[a];
        b = T[b];
        b++;
        // cout << a << " "<< b << endl;
        int x = A[b] - A[a];
        int y = B[b] - B[a];
        int z = C[b] - C[a];
        cout << min({x+y,y+z,z+x}) << endl;
    }
}