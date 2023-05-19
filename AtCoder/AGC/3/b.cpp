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
ll A[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll res = 0 ;
    rep(i,n){
        if(i > 0){
            if(A[i-1] & 1 && A[i] > 0){
                res++ ;
                A[i]-- ;
            }
        }
        res += A[i] / 2 ;
        A[i] %= 2 ;
    }
    cout << res << endl ;
}