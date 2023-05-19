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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[202020] ;
ll mp[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        cin >> A[i] ;
        mp[A[i]]++ ;
    }
    ll res = 0 ;
    rrep(i,1,200001){
        for(ll j = 1 ; i * j <= 200000 ; j++){
            res += mp[i] * mp[j] * mp[i*j] ;
        }
    }
    cout << res << endl ;
}