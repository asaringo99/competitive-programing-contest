#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , m ;
P A[101010] ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> n >> m ;
    rep(i,m) cin >> A[i].second >> A[i].first ;
    sort(A,A+m) ;
    ll g = n , res = 0 ;
    for(int i = 0 ; i < m ; i++){
        g = gcd(g,A[i].second) ;
        res += (n / g - 1) * g * A[i].first ;
        n = g ;
    }
    if(n == 1) cout << res << endl ;
    else cout << -1 << endl ;
}