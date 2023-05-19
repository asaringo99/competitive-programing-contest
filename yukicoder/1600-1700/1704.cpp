#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
int n , t ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

vector<vector<ll>> A(6,vector<ll>(6)) ;

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

    vector<vector<ll>> dynamic(vector<vector<ll>> A , ll k){
        int n = A.size() ;
        vector<vector<ll>> res(n,vector<ll>(1,0)) ;
        res[0][0] = 1 ;
        while(k > 0){
            if(k & 1) res = calculation(A,res) ;
            A = calculation(A,A) ;
            k >>= 1 ;
        }
        return res ;
    }

    ll slv(vector<vector<ll>> res){
        int n = res.size() ;
        ll ans = 0 ;
        rep(i,n) (ans += res[i][0]) %= mod ;
        return ans ;
    }
};

int main(){
    cin >> t ;
    rep(i,3) A[i*2][i*2] = powmod(3,mod-2) ;
    rep(i,3) A[i*2][i*2+1] = 1 ;
    rep(i,3) rep(j,2) A[i*2+1][(i*2+2*(j+1))%6] = powmod(3,mod-2) % mod ;
    rep(i,t){
        cin >> n ;
        MATRIX mtx ;
        cout << mtx.dynamic(A,n)[0][0] << endl ;
    }
}