#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int t ;

int main(){
    cin >> t ;
    rep(i,t){
        ll h , w , d ;
        cin >> h >> w >> d ;
        ll v = min(h,w) ;
        if(v * v + 1 <= d * d) cout << "N" << endl ;
        else if(h % 2 == 0 && w <= d) cout << "N" << endl ;
        else if(w % 2 == 0 && h <= d) cout << "N" << endl ;
        else cout << "S" << endl ;
    }
}