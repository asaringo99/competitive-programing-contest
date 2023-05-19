#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

ll r , b , x , y ;

ll f(ll s){
    if(r / x < s || b < s) return 0 ;
    ll t1 = r - x * s ;
    ll t2 = (b - s) / y ;
    // cout << s << " " << t1 << endl ;
    return s + min(t1,t2) ;
}

int main(){
    cin >> r >> b >> x >> y ;
    ll lef = 0 , rig = 1e18 , count = 0 ;
    while(count < 101010){
        ll lm = (2 * lef + rig) / 3 , rm = (lef + 2 * rig) / 3 ;
        if(f(lm) < f(rm)) lef = lm ;
        else rig = rm ;
        count++ ;
    }
    ll res = -1 ;
    rrep(i,max(0LL,lef-10),lef+11) chmax(res,f(i)) ;
    cout << res << endl ;
}