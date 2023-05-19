#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

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

int n ;
ll A[101010] ;

int main(){
    cin >> n ;
    int m = 0 ;
    bool ok = false ;
    rep(i,n){
        int a ;
        cin >> a ;
        if(i == 0 && a != 0) ok = true ;
        A[a]++ ;
        chmax(m,a) ;
    }
    if(ok || A[0] != 1){
        cout << 0 << endl ;
        return 0 ;
    }
    ll res = 1 ;
    rrep(i,1,m+1){
        ll MOD = A[i] * (A[i] - 1) / 2 ;
        (res *= powmod((powmod(2,A[i-1])-1+mod)%mod,A[i]) * powmod(2,MOD) % mod) %= mod ;
    }
    cout << res << endl ;
}