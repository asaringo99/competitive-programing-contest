#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int mod = 1000000007 ;

struct XOR{
    // 繰り返し二乗法
    ll powmod(ll x , ll n){
        ll res = 1 ;
        while(n > 0){
            if(n & 1) res = res * x % mod ;
            x = x * x % mod ;
            n >>= 1 ;
        }
        return res ;
    }

    //for(i = 1 ~ n - 1) for(j = i + 1 ~ n) Xi xor Xj の計算
    ll get_sum(vector<ll> A){
        // 前処理
        int n = A.size() ;
        vector<int> X(61,0) ;
        for(int i = 0 ; i < n ; i++){
            ll a = A[i] ;
            for(int j = 0 ; j <= 60 ; j++){
                if(a >> j & 1) X[j]++ ;
            }
        }
        // 計算
        ll res = 0 ;
        for(int i = 0 ; i < n - 1 ; i++){
            ll a = A[i] ;
            for(int j = 0 ; j <= 60 ; j++){
                if(a >> j & 1){
                    res += powmod(2,j) * (n - i - X[j]) ;
                    X[j]-- ;
                }
                else{
                    res += powmod(2,j) * X[j] ;
                }
                res %= mod ;
            }
        }
        return res ;
    }
};

int n ; 

// ABC147D
int main(){
    cin >> n ;
    vector<ll> A(n) ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    XOR slv ;
    cout << slv.get_sum(A) << endl ;
}