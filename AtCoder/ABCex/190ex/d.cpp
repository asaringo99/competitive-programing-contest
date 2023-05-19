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

ll n ;

int main(){
    cin >> n ;
    n *= 2 ;
    ll res = 0 ;
    for(ll i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            if((n / i - i) % 2 == 1) res += 2 ;
        }
    }
    cout << res << endl ;
}