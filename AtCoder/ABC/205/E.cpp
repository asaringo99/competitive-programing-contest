#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e6
#define mod (ll)(1e9+7)

ll pes[MAX_N+10] ; // (n!)^(p-2) (mod p) を格納
ll tes[MAX_N+10] ; // (n!) (mod p) を格納

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

void init(){
    powmod() ;
    invmod() ;
}

int n , m , k ;

int main(){
    // pesが逆元の階乗(1/n!)のmod配列
    // tesが階乗(n!)のmod配列
    init() ;

    cin >> n >> m >> k ;
    ll res = 0 ;
    for(int i = m ; i <= n + m - k ; i++){
        if(i < 2) continue ;
        res += combination(i,2) ;
        // cout << i << " " << k << " " << combination(i,k+1) << endl ;
        res %= mod ;
    }
    cout << res << endl ;
}