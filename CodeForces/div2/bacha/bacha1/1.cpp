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

int t ;
vector<ll> T ;
vector<P> vec ;

ll dfs(ll v , ll n){
    if(v <= n) return v ;
    auto it = lower_bound(T.begin(),T.end(),v) ;
    ll id = it - T.begin() ;
    id-- ;
    ll pos = v - T[id] ;
    auto [l,r] = vec[id-1] ;
    pos = l + pos - 1 ;
    return dfs(pos,n) ;
}

void solve(){
    int n , c , q ;
    string S ;
    cin >> n >> c >> q >> S ;
    T = {} ;
    vec = {} ;
    T.push_back(0) ;
    T.push_back(n) ;
    ll sum = n ;
    rep(i,c){
        ll l , r ;
        cin >> l >> r ;
        vec.push_back(P(l,r)) ;
        sum += r - l + 1 ;
        T.push_back(sum) ;
    }
    rep(i,q){
        ll k ;
        cin >> k ;
        ll pos = dfs(k,n) ;
        cout << S[pos-1] << endl ;
    }
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}