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

const ld pi = 3.14159265358979 ;

ld a , b , d ;

int main(){
    fast_input_output
    cin >> a >> b >> d ;
    ld x = a * cos(d * pi / 180) - b * sin(d * pi / 180) ;
    ld y = b * cos(d * pi / 180) + a * sin(d * pi / 180) ;
    cout << fixed << setprecision(25) << x << " " << y << endl ;
}