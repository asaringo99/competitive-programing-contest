#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
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
    //加算
    void add(T i , T x){
        i++ ;
        while(i <= n){
            bit[i] += x ;
            i += i & -i ;
        }
    }
    //総和
    T sum(int i){
        i++ ;
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

ll n , k ;
ll A[202020] , S[202020] , X[202020] , Y[202020] ;
unordered_map<int,int> mp ;


int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) S[i+1] = S[i] + A[i] - k ;
    rep(i,n+1) X[i] = S[i] ;
    sort(X,X+n+1) ;
    rep(i,n+1){
        int id = lower_bound(X,X+n,S[i]) - X ;
        Y[i] = id + mp[id] ;
        mp[id]++ ;
    }
    BinaryIndexedTree<ll> BIT(n + 10) ;
    cout << BIT.lower_count(Y,n+1) << endl ;
}