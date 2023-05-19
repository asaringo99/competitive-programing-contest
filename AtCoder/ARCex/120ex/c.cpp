#include <bits/stdc++.h>
using namespace std ;
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

const int MAX_N = 1 << 18 ;

template<typename T>
struct BinaryIndexedTree {
    T bit[MAX_N + 1] ; //bit[0] = 0
    int n ;
    
    //コンストラクタ
    BinaryIndexedTree(int n_){
        n = n_ ;
        memset(bit,0,sizeof(bit)) ;
    }
    //加算 i > 0
    void add(T i , T x){
        while(i <= n){
            bit[i] += x ;
            i += i & -i ;
        }
    }
    //総和: [0,i] , i > 0
    T sum(int i){
        T s = 0 ;
        while(i > 0){
            s += bit[i] ;
            i -= i & -i ; // iから(i & -i)を引く
        }
        return s ;
    }
    //区間和: [i,j] i,j >= 1
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
    T inversion(int *A , int n_){
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

int n ;
int A[202020] , B[202020] ;
P X[202020] ;
int Y[202020] ;
map<int,int> mp ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] , A[i] += i ;
    rep(i,n) cin >> B[i] , B[i] += i ;
    rep(i,n) X[i] = P(A[i],i+1) ;
    sort(X,X+n) ;
    bool ok = true ;
    rep(i,n){
        auto it = lower_bound(X,X+n,P(B[i],mp[B[i]])) ;
        P p = *it ;
        Y[i] = p.second ;
        if(it == X+n || B[i] != p.first) ok = false ;
        mp[B[i]] = p.second + 1 ;
    }
    if(!ok){
        cout << -1 << endl ;
        return 0 ;
    }
    BinaryIndexedTree<ll> bit(n+1) ;
    cout << bit.inversion(Y,n) << endl ;

}