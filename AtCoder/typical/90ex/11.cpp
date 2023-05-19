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
TP A[5050] ;
ll dp[5050] ;

int main(){
    cin >> n ;
    rep(i,n){
        int d , c , s ;
        cin >> d >> c >> s ;
        A[i] = {d,c,s} ;
    }
    sort(A,A+n) ;
    ll res = 0 ;
    rep(i,n){
        ll d , c , s ;
        tie(d,c,s) = A[i] ;
        for(int j = d ; j >= 0 ; j--){
            if(j - c < 0) continue ;
            if(j <= d) chmax(dp[j],dp[j-c]+s) ;
            chmax(res,dp[j]) ;
        }
    }
    cout << res << endl ;
}