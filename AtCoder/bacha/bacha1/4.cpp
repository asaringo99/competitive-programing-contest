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

ll n ;

int main(){
    // fast_input_output
    cout << 1100144LL * 1100144LL % 20200920 * 1100144LL % 20200920 << endl ;
    cin >> n ;
    ll k = n ;
    vector<ll> res ;
    for(ll x = 1 ; x * x <= k ; x++){
        if(k % x == 0){
            res.push_back(x) ;
            if(x * x != k) res.push_back(k/x) ;
        }
    }
    sort(res.begin(),res.end()) ;
    for(ll u : res) cout << u << endl ;
}