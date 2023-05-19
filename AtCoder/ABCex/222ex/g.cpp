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

int n ;

void solve(){
    ll k ;
    cin >> k ;
    if(k == 2 || k == 1){
        cout << 1 << endl ;
        return ;
    }
    if(k % 2 == 0 || k % 5 == 0){
        cout << -1 << endl ;
        return ;
    }
    ll x = k ;
    for(ll i = 2 ; i * i <= k ; i++){
        if(k % i != 0) continue;
        while(k % i == 0){
            k /= i ;
        }
        x = x - x / i ;
    }
    if(k != 1) x = x - x / k ;
    cout << x << endl ;
}

int main(){
    // fast_input_output
    cin >> n ;
    rep(i,n) solve() ;
}