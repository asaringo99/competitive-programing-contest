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

int W , H ;
vector<P> p ;

int main(){
    fast_input_output
    cin >> H >> W ;
    rep(i,H) {
        ll v ;
        cin >> v ;
        p.push_back(P(v,0)) ;
    }
    rep(i,W) {
        ll v ;
        cin >> v ;
        p.push_back(P(v,1)) ;
    }
    sort(p.begin(),p.end()) ;
    ll res = 0 ;
    int n = H + W ;
    rep(i,n){
        auto [val,id] = p[i] ;
        if(id == 0) res += val * (W + 1) , H-- ;
        if(id == 1) res += val * (H + 1) , W-- ;
    }
    cout << res << endl ;
}