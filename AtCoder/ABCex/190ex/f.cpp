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

template<typename T>
struct BinaryIndexedTree {

    vector<T> bit ; //bit[0] = 0
    int n ;
    
    //コンストラクタ
    BinaryIndexedTree(int n_){
        n = n_ ;
        bit.resize(n+1,0) ;
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

int n ;
ll A[303030] ;
vector<int> X ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] , A[i]++ , X.push_back(A[i]) ;
    sort(X.begin(),X.end()) ;
    BinaryIndexedTree<ll> bit(n) ;
    ll inv = bit.inversion(A,n) ;
    rep(i,n){
        cout << inv << endl ;
        inv -= n - 1 ;
        auto it = upper_bound(X.begin(),X.end(),A[i]) ;
        int id = it - X.begin() ;
        inv += n - id ;
        inv += (n - 1) - (id - 1) ;
    }
}