#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , a , b;
map<P,int> mp ;

int main(){
    cin >> n >> a >> b ;
    int res = 0 ;
    rep(i,n){
        int p , q , r , s ;
        cin >> p >> q >> r >> s ;
        p-- ; q-- ;
        rrep(x,p,r) rrep(y,q,s){
            mp[P(x,y)]++ ;
            chmax(res,mp[P(x,y)]) ;
        }
    }
    int sum = 0 ;
    for(auto it : mp) if(it.second == res) sum++ ;
    cout << res << endl<< sum << endl ;
}