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
ll a , b ;

int main(){
    fast_input_output
    cin >> a >> b ;
    ll bit_a = 0 , bit_b = 0 ;
    rep(i,40){
        if(a >> i & 1) bit_a = i ;
        if(b >> i & 1) bit_b = i ;
    }
    if(bit_a != bit_b){
        cout << min(a,b) << endl ;
        return 0 ;
    }
    cout << (1 << min(bit_a,bit_b)) - 1 << endl ;
}