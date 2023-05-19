#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;
const int MAX_N = 303030 ;

// 繰り返し二乗法
inline ll powmod(ll A , ll N){
    ll res = 1 ;
    while(N > 0){
        if(N & 1) res = (res * A) % mod ;
        A = (A * A) % mod ;
        N >>= 1 ;
    }
    return res % mod ;
}

//nCrの計算
inline ll combination(ll n , ll r , ll div){
    ll res = 1 ;
    rep(i,r) (res *= (n-i) % mod) %= mod ;
    (res *= div) %= mod ;
    return res ;
}

int n , k ;
ll A[101010] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    ll sum = 0 ;
    rrep(i,1,n) sum += A[i] ;
    if(A[0] < sum + k){
        cout << 0 << endl ;
        return 0 ;
    }
    ll res = 1 , div = 1 ;
    rep(i,k-1) (div *= powmod(k-1-i,mod-2)) %= mod ;
    rrep(i,1,n){
        (res *= combination(A[i]+k-1,k-1,div)) %= mod ;
    }
    A[0] -= sum + k ;
    (res *= combination(A[0]+k-1,k-1,div)) %= mod ;
    cout << res << endl ;
}