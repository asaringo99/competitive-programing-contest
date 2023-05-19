#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

ll powmod(ll A , ll N){
    ll res = 1 ;
    while(N > 0){
        if(N & 1) res = (res * A) % mod ;
        A = (A * A) % mod ;
        N >>= 1 ;
    }
    return res % mod ;
}

ll combination(ll n , ll r){
    ll res = 1 ;
    for(ll i = 0 ; i < r ; i++) (res *= (n - i)) %= mod ;
    for(ll i = 1 ; i <= r ; i++) (res *= powmod(i,mod-2)) %= mod ;
    return res ;
}

int n ;
ll A[2020]  ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll fir = -1 , las = -1 , sum = 0 , res = 1 ;
    rep(i,n-1){
        if(A[i] != -1 && A[i+1] == -1){
            fir = A[i] ;
        }
        if(A[i] == -1) sum++ ;
        if(A[i] == -1 && A[i+1] != -1){
            las = A[i+1] ;
            (res *= combination(las-fir+sum,sum)) %= mod ;
            sum = 0 ;
        }
    }
    cout << res << endl ;
}