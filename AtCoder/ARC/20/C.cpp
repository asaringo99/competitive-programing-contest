#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll mod ;
ll A[10101] , L[10101] ;

struct MATRIX{
    // A * B
    vector<vector<ll>> calculation(vector<vector<ll>> X , vector<vector<ll>> Y){
        int x = X.size() , y = Y[0].size() , n = Y.size() ;
        vector<vector<ll>> res(x,vector<ll>(y)) ;
        rep(i,x) rep(j,y) rep(k,n) {
            (res[i][j] += X[i][k] * Y[k][j]) %= mod ;
        }
        return res ;
    }

    vector<vector<ll>> dynamic(vector<vector<ll>> A , vector<vector<ll>> res , ll k){
        int n = A.size() ;
        while(k > 0){
            if(k & 1) res = calculation(A,res) ;
            A = calculation(A,A) ;
            k >>= 1 ;
        }
        return res ;
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

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] >> L[i] ;
    cin >> mod ;
    ll sum = 0 ;
    ll res = 0 ;
    rep(i,n){
        ll a = A[n-1-i] , l = L[n-1-i] ;
        vector<vector<ll>> vec(2,vector<ll>(2,0)) , b(2,vector<ll>(1,0)) ;
        vec[0][0] = powmod(10,to_string(a).size()) ;
        vec[0][1] = a ;
        vec[1][0] = 0 ;
        vec[1][1] = 1 ;
        b[0][0] = a ;
        b[1][0] = 1 ;
        MATRIX mat ;
        res += mat.dynamic(vec,b,l-1)[0][0] * powmod(10,sum) % mod ;
        res %= mod ;
        ll m = to_string(a).size() ;
        m *= l ;
        sum += m ;
    }
    cout << res << endl ;
}