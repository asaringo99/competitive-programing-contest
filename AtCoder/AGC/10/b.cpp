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

ll n ;
ll A[101010] ;

int main(){
    cin >> n ;
    ll sum = 0 ;
    rep(i,n) cin >> A[i] , sum += A[i] ;
    ll v = n * (n + 1) / 2 ;
    if(sum % v != 0){
        cout << "NO" << endl ;
        return 0 ;
    }
    bool ok = true ;
    ll k = sum / v ;
    rep(i,n){
        ll x = k + A[i] - A[(i+1)%n] ;
        if(x % n != 0 || x < 0) ok = false; 
    }
    if(ok) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}