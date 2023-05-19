#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

// 座標圧縮
struct Compress{
    private :
        int n ;
        vector<int> vec ; // 元の値の座標圧縮後の値
        unordered_map<ll,ll> mp ; // 元の値がどの値に変換されたか
        vector<ll> A ;

        void build_(){
            action() ;
        }

        void build_(vector<ll> A_){
            A = A_ ;
            action() ;
        }

        void action(){
            n = A.size() ;
            vector<int> B ;
            set<int> st ;
            for(int i = 0 ; i < n ; i++) st.insert(A[i]) ;
            for(int u : st) B.push_back(u) ;
            // for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
            vec.resize(n) ;
            for(int i = 0 ; i < n ; i++){
                auto it = lower_bound(B.begin(),B.end(),A[i]) ;
                vec[i] = it - B.begin() ;
                mp[A[i]] = it - B.begin();
            }
        }

    public :
        Compress(vector<ll> A_) : A(A_) {} ; // vector<ll> A を持っておく
        Compress() {} ; // 何もしないコンストラクタ
        void build() { build_() ; } // ビルドする (既に vector<ll> の情報を持つようにしておく)
        void build(vector<ll> A_) { build_(A_) ; } // vector<ll> A を座標圧縮
        size_t size() {return vec.size() ; }
        inline int at(ll i) { return mp[i] ; } // 例: 341234125353 -> 6 的な
        vector<int> get_compress() { return vec ; }
        inline int operator [] (int i) { return vec[i] ; } // 例: 5番目の値は -> 11 的な
};

struct Compress2D{

    private :
        int H , W ; // 座業圧縮後の 縦, 横の長さ
        Compress X , Y ; // 縦, 横 座標圧縮後の値を持つ
        vector<vector<char>> C ; // 座標圧縮後の二次元平面
        vector<vector<int>> S , T ; // 縦,横にimos法を行うための二次元配列

        // H_: 元の縦の長さ, W_: 元の横の長さ
        // X_: 列ベクトル,   Y_: 行ベクトル
        inline void init_(ll H_ , ll W_ , vector<ll> X_ , vector<ll> Y_){
            X.build(X_) ;
            Y.build(Y_) ;
            H = X.at(H_) ;
            W = Y.at(W_) ;
            C.resize(H,vector<char>(W,'.')) ;
            S.resize(H+1,vector<int>(W+1,0)) ;
            T.resize(H+1,vector<int>(W+1,0)) ;
        }

        // x が縦方向に対する座標, y が横方向に対する座標
        // sx: 始点の x 座標, sy: 始点の y 座標, gx: 終点の x 座標, gy: 終点の y 座標
        void input_(ll sx , ll sy , ll gx , ll gy) {
            sx = X.at(sx) ;
            gx = X.at(gx) ;
            sy = Y.at(sy) ;
            gy = Y.at(gy) ;
            for(int x = sx ; x < gx ; x++){
                S[x][sy]++ ;
                S[x][gy]-- ;
            }
            for(int y = sy ; y < gy ; y++){
                T[sx][y]++ ;
                T[gx][y]-- ;
            }
        }

        // imos法を x 座標, y 座標のどちらに対しても行う
        void build_(){
            for(int i = 0 ; i < H ; i++){
                int sum = 0 ;
                for(int j = 0 ; j < W ; j++){
                    sum += S[i][j] ;
                    if(sum > 0) C[i][j] = '#' ;
                }
            }
            for(int j = 0 ; j < W ; j++){
                int sum = 0 ;
                for(int i = 0 ; i < H ; i++){
                    sum += T[i][j] ;
                    if(sum > 0) C[i][j] = '#' ;
                }
            }
        }

    public :
        // 座標圧縮前の縦幅 H, 横幅 W, 各x座標の情報 X, 各y座標の情報 Y
        Compress2D(ll H_ , ll W_ , vector<ll> X_ , vector<ll> Y_) { init_(H_,W_,X_,Y_) ; }
        Compress2D() {}
        // 座標圧縮前の縦幅 H, 横幅 W, 各x座標の情報 X, 各y座標の情報 Y
        void init(ll H_ , ll W_ , vector<ll> X_ , vector<ll> Y_) { init_(H_,W_,X_,Y_) ; }
        // [sx,gx) , [sy,gy) の区間になるようにする
        void input(ll sx , ll sy , ll gx , ll gy) { input_(sx,sy,gx,gy) ; }
        // 二次元imos法を行う
        void build() { build_() ; }
        int hight(){ return H ; }
        int width(){ return W ; }
        vector<vector<char>> get_2d_compress() { return C ; }
        P at(ll x , ll y) { return P(X.at(x) , Y.at(y)) ; }
        inline vector<char> operator [] (int i) { return C[i] ; }
};

// function                    : return               : description
// ----------------------------------------------------------------
// constractor()              : constractor          : 宣言だけ行う
// constractor(H,W,vecX,vecY) : constractor          : 座標圧縮する H,Wは元々の長さ
// init(H,W,vecX,vecY)        : void                 : 座標圧縮する H,Wは元々の長さ
// input(sx,sy,gx,gy)         : void                 : 元の (sx,sy) - (gx,gy) の長方形情報を入力する (imos法の準備)
// build()                    : void                 : imos法を行い、座標圧縮する
// hight()                    : int                  : 座標圧縮後の縦幅
// width()                    : int                  : 座標圧縮後の横幅
// get_2d_compress()          : vecort<vector<char>> : 二次元座標圧縮で得られた平面を取得
// at(x,y)                    : pair<ll,ll>          : 元々の座標が座圧後にどんな座標になったか
// *注意* 取り敢えず全てをコピペすることを奨励

int W , H , q ;
vector<TP> X ;
Compress2D S ;
vector<vector<char>> C ;

int dx[] = {0,0,1,-1} , dy[] = {1,-1,0,0} ;
bool used[3030][3030] ;

void bfs(int sx , int sy){
    queue<P> que ;
    que.push(P(sx,sy)) ;
    while(!que.empty()){
        auto[x,y] = que.front() ; que.pop() ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(nx < 0 || nx >= H || ny < 0 || ny >= W || C[nx][ny] != '.' || used[nx][ny]) continue;
            used[nx][ny] = true ;
            que.push(P(nx,ny)) ;
        }
    }
}

int main(){
    cin >> W >> H >> q ;
    vector<ll> h , w ;
    h.push_back(0) ;
    h.push_back(H) ;
    w.push_back(0) ;
    w.push_back(W) ;
    rep(i,q){
        int sx , sy , gx , gy ;
        cin >> sy >> sx >> gy >> gx ;
        X.push_back({sx,sy,gx,gy}) ;
        h.push_back(sx) ;
        h.push_back(gx) ;
        w.push_back(sy) ;
        w.push_back(gy) ;
    }
    S.init(H,W,h,w) ;
    rep(i,q){
        auto [sx,sy,gx,gy] = X[i] ;
        S.input(sx,sy,gx,gy) ;
    }
    S.build() ;
    H = S.hight() ;
    W = S.width() ;
    C = S.get_2d_compress() ;
    int res = 0 ;
    rep(i,H) rep(j,W){
        if(C[i][j] == '.' && !used[i][j]) bfs(i,j) , res++ ;
    }
    cout << res << endl ;
}