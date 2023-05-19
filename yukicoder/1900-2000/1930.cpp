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

int t ;

void solve(){
    ll l , r ;
    cin >> l >> r ;
    if((r - l) % 2 == 0){
        ll x = (r - l) / 2 ;
        if(x % 4 == 0) cout << (ll)(l + r) << endl ;
        else if(x % 4 == 2) cout << (ll)(l + r) + 1LL << endl ;
        else if(x % 4 == 1) cout << 1 << endl ;
        else cout << 0 << endl ;
    }
    else{
        ll x = (r - l) / 2 ;
        if(x % 4 == 0) cout << 1 << endl ;
        else if(x % 4 == 2) cout << 0 << endl ;
        else if(x % 4 == 1) cout << 1 << endl ;
        else cout << 0 << endl ;
    }
}

int main(){
    fast_input_output
    cin >> t ;
    rep(i,t) solve() ;
}