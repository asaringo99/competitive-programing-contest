#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"

template<typename T>
struct SegmentTree2D{
    private :
        const ll inf = 1001001001001001001 ;
        vector<vector<T>> dat ;
        int h , w ;

        void update_(int x , int y , T val){
            x += h - 1 ;
            int k = y + w - 1 ;
            dat[x][k] = val ;
            while(k > 0){
                k = (k - 1) / 2 ;
                dat[x][k] = max(dat[x][2*k+1],dat[x][2*k+2]) ;
            }
            while(x > 0){
                x = (x - 1) / 2 ;
                k = y + w - 1 ;
                dat[x][k] = max(dat[2*x+1][k],dat[2*x+2][k]) ;
                while(k > 0){
                    k = (k - 1) / 2 ;
                    dat[x][k] = max(dat[2*x+1][k],dat[2*x+2][k]) ;
                }
            }
        }

        T query_x(int a , int b , int k , int l , int r , int s , int t){
            if(r <= a || b <= l) return -inf ;
            if(a <= l && r <= b) return query_y(s,t,0,0,w,k) ;
            
            T lef = query_x(a,b,2*k+1,l,(l+r)/2,s,t) ;
            T rig = query_x(a,b,2*k+2,(l+r)/2,r,s,t) ;
            return max(lef,rig) ;
        }

        T query_y(int a , int b , int k , int l , int r , int x){
            if(r <= a || b <= l) return -inf ;
            if(a <= l && r <= b) return dat[x][k] ;
            T lef = query_y(a,b,2*k+1,l,(l+r)/2,x) ;
            T rig = query_y(a,b,2*k+2,(l+r)/2,r,x) ;
            return max(lef,rig) ;
        }

    public :
        SegmentTree2D(int h_ , int w_) : h(h_) , w(w_) {
            h = 1 ;
            w = 1 ;
            while(h < h_) h *= 2 ;
            while(w < w_) w *= 2 ;
            dat.resize(2*h-1,vector<T>(2*w-1,-inf)) ;
        }

        void update(int x , int y , T val) { update_(x,y,val) ; }
        T query(int x1 , int x2 , int y1 , int y2) { return query_x(x1,x2,0,0,h,y1,y2) ; }
};

int H , W , h1 , w1 , h2 , w2 ;
ll A[1010][1010] ;
ll S[1010][1010] ;

int main(){
    fast_input_output
    cin >> H >> W >> h1 >> w1 >> h2 >> w2 ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    rep(i,H) rep(j,W) S[i+1][j+1] = -S[i][j] + A[i][j] + S[i+1][j] + S[i][j+1] ;
    if(h1 <= h2 && w1 <= w2){
        cout << 0 << endl ;
        return 0 ;
    }
    SegmentTree2D<ll> segtree(H+1,W+1) ;
    rrep(i,1,H+1) rrep(j,1,W+1){
        if(h1 < h2 && w1 > w2){
            if(i + h1 - 1 > H || j + w2 - 1 > W) continue ;
            int h = i + h1 - 1 , w = j + w2 - 1 ;
            ll s = S[h][w] - S[h][j-1] - S[i-1][w] + S[i-1][j-1] ;
            segtree.update(i,j,s) ;
        }
        else if(w1 < w2 && h1 > h2){
            if(i + h2 - 1 > H || j + w1 - 1 > W) continue ;
            int h = i + h2 - 1 , w = j + w1 - 1 ;
            ll s = S[h][w] - S[h][j-1] - S[i-1][w] + S[i-1][j-1] ;
            segtree.update(i,j,s) ;
        }
        else{
            if(i + h2 - 1 > H || j + w2 - 1 > W) continue ;
            int h = i + h2 - 1 , w = j + w2 - 1 ;
            ll s = S[h][w] - S[h][j-1] - S[i-1][w] + S[i-1][j-1] ;
            segtree.update(i,j,s) ;
        }
    }
    ll res = 0 ;
    rrep(i,1,H+1) rrep(j,1,W+1){
        int h = i + h1 - 1 , w = j + w1 - 1 ;
        if(h > H || w > W) continue ;
        ll s = S[h][w] - S[h][j-1] - S[i-1][w] + S[i-1][j-1] , t ;
        if(h1 < h2 && w1 > w2){
            int sh = i , gh = i + 1 , sw = j , gw = j + w1 - w2 + 1 ;
            if(gh > H + 1 || gw > W + 1) continue;
            t = segtree.query(sh,gh,sw,gw) ;
        }
        else if(w1 < w2 && h1 > h2){
            int sh = i , gh = i + h1 - h2 + 1 , sw = j , gw = j + 1 ;
            if(gh > H + 1 || gw > W + 1) continue;
            t = segtree.query(sh,gh,sw,gw) ;
        }
        else{
            int sh = i , gh = i + h1 - h2 + 1 , sw = j , gw = j + w1 - w2 + 1 ;
            if(gh > H + 1 || gw > W + 1) continue;
            t = segtree.query(sh,gh,sw,gw) ;
        }
        chmax(res,s-t) ;
    }
    cout << res << endl ;
}