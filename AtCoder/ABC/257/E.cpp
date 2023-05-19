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
#define s "123456789"

int n ;
ll C[10] ;

int main(){
    cin >> n ;
    rep(i,9) cin >> C[i] ;
    ll res = -1 , val = 1e8 ;
    rep(i,9) chmax(res,n/C[i]) ;
    rep(i,9) chmin(val,C[i]) ;
    vector<int> vec ;
    while(res > 0){
        int add = -1 ;
        rep(i,9) {
            if(n - C[i] >= (res - 1) * val){
                add = i ;
            }
        }
        n -= C[add] ;
        res-- ;
        vec.push_back(add+1) ;
    }
    sort(vec.begin(),vec.end(),greater<int>()) ;
    for(int u : vec) cout << u ; cout << endl ;
}