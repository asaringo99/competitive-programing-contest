#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;
const int MAX_N = 101010 ;

ll pes[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll tes[MAX_N+1] ; // (n!) (mod p) を格納

// 逆元(1/n)のmod計算
ll invmodcal(ll A , ll N){
    ll res = 1 ;
    while(N > 0){
        if(N & 1) res = (res * A) % mod ;
        A = (A * A) % mod ;
        N >>= 1 ;
    }
    return res % mod ;
}

// 階乗の逆元(n!)^(-1)のmodを配列に格納
void invmod(){
    pes[0] = 1 ; pes[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        pes[i] = invmodcal(i,mod-2) * pes[i-1] % mod ;
    }
}

// 階乗のmodを配列に格納
void powmod(){
    tes[0] = 1 ; tes[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        tes[i] = (tes[i-1] * i) % mod ;
    }
}

//nCrの計算
ll combination(ll n , ll r){
    return tes[n] * pes[n-r] % mod * pes[r] % mod ;
}

int n , m ;
ll A[101] ;
int dp[101][101010] ;

int main(){
    powmod() ; invmod() ;
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n,greater<ll>()) ;
    rep(i,n+1) rep(j,m+1) dp[i][j] = -1 ;
    dp[0][0] = 0 ;
    rrep(i,1,n+1){
        rep(j,m+1){
            if(dp[i-1][j] >= 0) dp[i][j] = dp[i][j] == -1 ? dp[i-1][j] : min(dp[i][j],dp[i-1][j]) ;
            if(j >= A[i-1] && dp[i][j-A[i-1]] >= 0) {
                dp[i][j] = dp[i][j] == -1 ? dp[i][j-A[i-1]]+1 : min(dp[i][j],dp[i][j-A[i-1]]+1) ;
            }
        }
    }
    ll res = 1 ;
    rrep(i,1,m+1){
        if(dp[n][i] == -1) continue ;
        ll put = i - dp[n][i] ;
        ll tab = m - dp[n][i] ;
        ( res += combination(tab,put)) %= mod ;
    }
    cout << res << endl ;
}