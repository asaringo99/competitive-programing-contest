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

int a , b , c , x ;

int main(){
    cin >> a >> b >> c >> x ;
    if(x <= a) cout << 1 << endl ;
    else if(x <= b){
        cout << fixed << setprecision(25) << (ld)c / (b - a) << endl ;
    }
    else cout << 0 << endl ;
}