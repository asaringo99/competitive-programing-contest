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

int n , m ;
ll A[202020] , S[202020] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] ;
    rep(i,m){
        ll x ;
        cin >> x ;
        auto it = lower_bound(S,S+n+1,x) ;
        cout << it - S << " " ; it-- ;
        cout << x - *it << endl ;
    }
}