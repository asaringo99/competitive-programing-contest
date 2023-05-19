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

ll n , w ;
ll A[1010] ;

int main(){
    cin >> n >> w ;
    rep(i,n) cin >> A[i] ;
    ll up = w , down = 0 , sum = 0 ;
    rep(i,n){
        sum += A[i] ;
        if(sum > 0) chmin(up,w-sum) ;
        if(sum < 0) chmax(down,-sum) ;
    }
    ll res = up - down + 1 ;
    res = res < 0 ? 0 : res ;
    cout << res << endl ;
}