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

int n , k ;

int main(){
    fast_input_output
    cin >> n >> k ;
    ll m = 1 << n ;
    if(n == 1 && k == 1){
        cout << -1 << endl ;
        return 0 ;
    }
    if(k == 0){
        cout << 0 << " " << 0 << " " ;
        rep(i,m) if(i != k) cout << i << " " ;
        rep(i,m) if(m - 1 - i != k) cout << m - 1 - i << " " ; cout << endl ;
        return 0 ;
    }
    if(m <= k){
        cout << -1 << endl ;
        return 0 ;
    }
    rep(i,m) if(i != k) cout << i << " " ;
    cout << k << " " ;
    rep(i,m) if(m - 1 - i != k) cout << m - 1 - i << " " ;
    cout << k << endl ;
}