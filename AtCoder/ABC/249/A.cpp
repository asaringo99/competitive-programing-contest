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

int a , b , c , d , e , f , x ;

int main(){
    fast_input_output
    cin >> a >> b >> c >> d >> e >> f >> x ;
    int g = a + c , h = d + f ;
    int ta = x / g * a * b , ao = x / h * d * e ;
    int mt = x % g <= a ? (x % g) * b : a * b ;
    int ma = x % h <= d ? (x % h) * e : d * e ;
    ta += mt ;
    ao += ma ;
    if(ta > ao) cout << "Takahashi" << endl ;
    else if(ta < ao) cout << "Aoki" << endl ;
    else cout << "Draw" << endl ;
} 