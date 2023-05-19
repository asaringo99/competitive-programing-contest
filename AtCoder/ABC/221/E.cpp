#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;
const int MAX_N = 303030 ;
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
            s %= mod ;
            i -= i & -i ; // iから(i & -i)を引く
        }
        return s ;
    }
};

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int n ;
P A[303030] ;

int main(){
    cin >> n ;
    int a;
    rep(i,n) cin >> a, A[i] = P(a,i+1) ;
    sort(A,A+n) ;

    BinaryIndexedTree<ll> bit(n+1);
    rrep(i,1,n) bit.add(i+1,powmod(2,i-1)) ;

    ll res = 0 ;
    rep(i,n){
        int k = A[i].second ;
        ll r = powmod(powmod(2,mod-2),k-1) ;
        res += (bit.sum(n) - bit.sum(k) + mod) % mod * r % mod ;
        res %= mod ;
        if(k != 1) bit.add(k,-powmod(2,k-2)) ;
    }
    cout << res << endl ;
}