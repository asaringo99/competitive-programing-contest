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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

ll L , R ;

int main(){
    cin >> L >> R ;
    ll res = 0 ;
    for(ll d = R - L ; d >= 1 ; d--){
        for(ll i = L ; i <= R - d ; i++){
            if(gcd(i,i+d) == 1){
                cout << d << endl ;
                return 0 ;
            }
        }
    }
}