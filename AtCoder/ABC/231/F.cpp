#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int MAX_N = 1 << 20 ;

template<typename T>
struct BinaryIndexedTree {

    T bit[MAX_N + 1] ; //bit[0] = 0
    int n ;
    
    //コンストラクタ
    BinaryIndexedTree(int n_){
        n = n_ ;
        memset(bit,0,sizeof(bit)) ;
    }
    //加算
    void add(T i , T x){
        while(i <= n){
            bit[i] += x ;
            i += i & -i ;
        }
    }
    //総和
    T sum(int i){
        T s = 0 ;
        while(i > 0){
            s += bit[i] ;
            i -= i & -i ; // iから(i & -i)を引く
        }
        return s ;
    }
    //区間和
    T secsum(int i , int j){
        return sum(j) - sum(i-1) ;
    }
    //二分探索
    T lower_bound(T x){
        if(x <= 0) return 0 ;
        int lef = 0 , rig = 1 ;
        while(rig < n) rig *= 2 ;
        while(rig > 0){
            if(lef + rig <= n && bit[lef + rig] < x){
                x -= bit[lef + rig] ;
                lef += rig ;
            }
            rig >>= 1 ;
        }
        return lef + 1 ;
    }

    //転倒数計算
    T inversion(T *A , int n_){
        T s = 0 ;
        for(int i = 0 ; i < n_ ; i++){
            s += i - sum(A[i]) ;
            add(A[i],1) ;
        }
        return s ;
    }

    //Si <= Sj の数
    T lower_count(T *A , int n_){
        T s = 0 ;
        for(int i = 0 ; i < n_ ; i++){
            s += sum(A[i]) ;
            add(A[i],1) ;
        }
        return s ;
    }
};

ll n ;
P X[202020] ;
set<ll> vec ;
map<ll,ll> mp ;
map<P,ll> mm ;

int main(){
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        vec.insert(a) ;
        X[i].first = a ;
    }
    rep(i,n){
        ll a ;
        cin >> a ;
        vec.insert(a) ;
        X[i].second = a ;
    }
    ll ttt = 0 ;
    for(int u : vec) mp[u] = ++ttt ;
    rep(i,n){
        X[i].first = mp[X[i].first] ;
        X[i].second = -mp[X[i].second] ;
    }
    sort(X,X+n) ;
    // rep(i,n) cout << X[i].first << " " << X[i].second << endl ;
    // rep(i,n) cout << X[i].first << " " << X[i].second << endl ;
    ll res = n ;
    BinaryIndexedTree<ll> bit(2*n+3) ;
    rep(i,n){
        res += bit.secsum(-X[i].second,2*n+1) ;
        bit.add(-X[i].second,1) ;
    }
    rep(i,n-1) if(X[i] == X[i+1]){
        mm[X[i]]++ ;
    }
    for(auto it : mm) res = res + it.second * (it.second + 1) / 2 ;
    cout << res << endl ;
}