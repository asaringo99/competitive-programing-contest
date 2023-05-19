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

ll n , a ,  b , c , d ;

int main(){
    cin >> n >> a >> b >> c >> d ;
    bool ok = false ;
    rrep(i,1,n-1){
        ll top = a + d * i , bot = a + c * i ;
        ll up = top - (n - 1 - i) * c , down = bot - (n - 1 - i) * d ;
        if(down <= b && b <= up) ok = true ;
    }
    if(ok) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}