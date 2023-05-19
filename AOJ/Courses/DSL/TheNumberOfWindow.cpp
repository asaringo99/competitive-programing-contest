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

int n , q ;
ll S[101010] , A[101010] ;

int main(){
    fast_input_output
    cin >> n >> q ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] ;
    rep(z,q){
        ll x , res = 0 ;
        cin >> x ;
        rep(i,n){
            auto it = upper_bound(S,S+n+1,S[i]+x) ; it-- ;
            int id = it - S ;
            res += id - i ;
        }
        cout << res << endl ;
    }
}