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
ll A[202020] ;

int main(){
    cin >> n >> k ;
    rrep(i,1,n+1) cin >> A[i] ;
    A[0] = 1 ;
    A[n+1] = 1e9+10 ;
    sort(A,A+n+2) ;
    if(A[k+1] - A[k] == 0){
        cout << -1 << endl ;
        return 0 ;
    }
    cout << A[k] << endl ;
    return 0 ;
}