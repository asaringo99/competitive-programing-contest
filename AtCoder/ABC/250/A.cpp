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

int h , w , r , c ;

int main(){
    fast_input_output
    cin >> h >> w >> r >> c ;
    int res = 4 ;
    if(h == 1 && w == 1){
        cout << 0 << endl ;
        return 0 ;
    }
    if(h == 1){
        res = 2 ;
        if(w == c || c == 1) res-- ;
        cout << res << endl ;
        return 0 ;
    }
    if(w == 1){
        res = 2 ;
        if(r == h || r == 1) res-- ;
        cout << res << endl ;
        return 0 ;
    }
    if(r == h || r == 1) res-- ;
    if(c == w || c == 1) res-- ;
    cout << res << endl ;
}