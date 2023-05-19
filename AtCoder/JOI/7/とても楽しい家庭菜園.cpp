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

int n ;
ll A[202020] , S[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll pls = 0 , mns = 0 ;
    rep(i,n-1) {
        S[i] = A[i+1] - A[i] ;
        if(S[i] >= 0) pls += S[i] + 1 ;
    }
    ll res = 1e16 ;
    chmin(res,pls+mns) ;
    rep(i,n-1){
        if(S[i] >= 0) pls -= S[i] + 1 ;
        if(S[i] <= 0) mns += -S[i] + 1 ;
        chmin(res,max(pls,mns)) ;
    }
    cout << res << endl ;
}