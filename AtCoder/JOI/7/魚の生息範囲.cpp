#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int,int,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
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
            set<T> st ;
            rep(i,n) st.insert(A[i]) ;
            A = {} ;
            for(T u : st) A.push_back(u) ;
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

int n , k ;
TP A[101] ;
ll S[101][101][101] ;

int main(){
    cin >> n >> k ;
    vector<int> XX , YY , ZZ ;
    rep(i,n){
        int r1 , r2 , c1 , c2 , d1 , d2 ;
        cin >> r1 >> c1 >> d1 >> r2 >> c2 >> d2 ;
        XX.push_back(r1) ;
        XX.push_back(r2) ;
        YY.push_back(c1) ;
        YY.push_back(c2) ;
        ZZ.push_back(d1) ;
        ZZ.push_back(d2) ;
        A[i] = {r1,r2,c1,c2,d1,d2} ;
    }
    Compress X(XX) , Y(YY) , Z(ZZ) ;
    int mx = 0 , my = 0 , mz = 0 ;
    rep(i,n){
        auto[sx,gx,sy,gy,sz,gz] = A[i] ;
        sx = X.encrypt(sx) ;
        gx = X.encrypt(gx) ;
        sy = Y.encrypt(sy) ;
        gy = Y.encrypt(gy) ;
        sz = Z.encrypt(sz) ;
        gz = Z.encrypt(gz) ;
        chmax(mx,gx) ;
        chmax(my,gy) ;
        chmax(mz,gz) ;
        rrep(x,sx,gx) rrep(y,sy,gy) S[sz][x][y]++ ;
        rrep(x,sx,gx) rrep(y,sy,gy) S[gz][x][y]-- ;
    }
    ll res = 0 ;
    rep(x,mx) rep(y,my){
        int sum = 0 ;
        ll dx = X.decrypt(x+1) - X.decrypt(x) ;
        ll dy = Y.decrypt(y+1) - Y.decrypt(y) ;
        rep(z,mz){
            ll dz = Z.decrypt(z+1) - Z.decrypt(z) ;
            sum += S[z][x][y] ;
            S[z][x][y] = sum ;
            if(sum >= k) res += dx * dy * dz ;
        }
    }
    cout << res << endl ;
}