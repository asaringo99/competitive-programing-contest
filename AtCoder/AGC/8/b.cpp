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

int n , k ;
ll A[101010] , L[101010] , R[101010] , S[101010] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] ;
    ll res = 0 ;
    rep(i,n){
        if(i + k == n){
            ll sum = 0 ;
            rrep(j,i,n) sum += A[j] ;
            chmax(res,L[i]+sum) ;
            break ;
        }
        ll val = A[i] > 0 ? A[i] : 0 ;
        L[i+1] = L[i] + val ;
    }
    rep(i,n){
        if(i + k == n){
            ll sum = 0 ;
            rrep(j,i,n) sum += A[n-1-j] ;
            chmax(res,R[i]+sum) ;
            break ;
        }
        ll val = A[n-1-i] > 0 ? A[n-1-i] : 0 ;
        R[i+1] = R[i] + val ;
    }
    rrep(i,1,n-k) res = max({res,L[i]+R[n-k-i],L[i]+R[n-k-i]+S[i+k]-S[i]}) ;
    cout << res << endl ;
}