#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
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

int n , q ;
int C[505050] , X[505050] ;
vector<P> query[505050] ;
int res[505050] ;

int main(){
    cin >> n >> q ;
    rrep(i,1,n+1) cin >> C[i] ;
    BinaryIndexedTree<ll> BIT(n+1) ;
    rrep(i,1,q+1){
        int l , r ;
        cin >> l >> r ;
        query[r].push_back(P(l,i)) ;
    }
    rrep(i,1,n+1){
        if(BIT.secsum(X[C[i]],X[C[i]]) > 0) BIT.add(X[C[i]],-1) ;
        BIT.add(i,1) ;
        X[C[i]] = i ;
        for(P p : query[i]){
            int l = p.first , id = p.second ;
            res[id] = BIT.secsum(l,i) ;
        }
    }
    rrep(i,1,q+1) cout << res[i] << endl ;
}