#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
int A[101] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n-1) cin >> A[i] ;
    ld res = 1000 ;
    rep(i,n-1) res *= (ld)((ld)1000 - A[n-2-i]) / 1000 ;
    res = (ld)1000 - res ;
    cout << fixed << setprecision(25) << res << endl ;
}