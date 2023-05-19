#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , k ;

const int mod = 1000000007 ;

vector<vector<ll>> A(55,vector<ll>(55)) ;

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
        vector<vector<ll>> res(n,vector<ll>(1,1)) ;
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
    cin >> n >> k ;
    rep(i,n) rep(j,n) cin >> A[j][i] ;
    MATRIX matrix ;
    cout << matrix.slv(matrix.dynamic(A,k)) << endl ;
}