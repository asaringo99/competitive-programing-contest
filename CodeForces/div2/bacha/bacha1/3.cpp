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
#define input(a) cin >> a
#define print(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl

template<typename T>
struct SegmentTree{
    int n , n_;
    vector<T> dat ;
    SegmentTree(int _n){
        n_ = _n ;
        n = 1 ;
        while(n < _n) n *= 2 ;
        dat.resize(2 * n - 1,0) ;
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
};

int zz ;
int n , q ;
int CX[202020] , CY[202020] ;

int main(){
    fast_input_output
    cin >> n >> q ;
    SegmentTree<int> X(n) , Y(n) ;
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            int x , y ;
            cin >> x >> y ;
            x-- ; y-- ;
            CX[x]++ ;
            CY[y]++ ;
            if(CX[x] == 1) X.add(x,1) ;
            if(CY[y] == 1) Y.add(y,1) ;
        }
        if(t == 2){
            int x , y ;
            cin >> x >> y ;
            x-- ; y-- ;
            CX[x]-- ;
            CY[y]-- ;
            if(CX[x] == 0) X.add(x,-1) ;
            if(CY[y] == 0) Y.add(y,-1) ;
        }
        if(t == 3){
            int sx , sy , gx , gy ;
            cin >> sx >> sy >> gx >> gy ;
            sx-- ; sy-- ;
            int xx = X.query(sx,gx) ;
            int yy = Y.query(sy,gy) ;
            if(xx == gx - sx || yy == gy - sy) cout << "Yes" <<endl ;
            else cout << "No" << endl ;
        }
    }
}