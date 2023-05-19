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

ll a , b , c , x ;

int main(){
    fast_input_output
    cin >> a >> b >> c >> x ;
    bool ok = false ;
    if(x % gcd(a,b) == 0) ok = true ;
    if(x % gcd(a,c) == 0) ok = true ;
    if(x % gcd(c,b) == 0) ok = true ;
    if(x % gcd(a,gcd(b,c)) == 0) ok = true ;
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}