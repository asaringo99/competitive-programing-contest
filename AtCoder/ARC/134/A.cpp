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

ll n , l , w ;
ll A[101010] ;

int main(){
    cin >> n  >> l >> w ;
    rep(i,n) cin >> A[i] ;
    A[n] = l ;
    ll res = 0 ;
    ll bef = 0 ;
    rep(i,n+1){
        if(bef < A[i]){
            ll mag = A[i] - bef ;
            ll val = mag / w ;
            if(mag % w != 0) val++ ;
            res += val ;
        } 
        bef = A[i] + w ;
    }
    cout << res << endl ;
}