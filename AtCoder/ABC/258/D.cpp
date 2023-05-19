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

ll n , x ;
ll A[202020] , B[202020] ;

int main(){
    fast_input_output
    cin >> n >> x ;
    rep(i,n) cin >> A[i] >> B[i] ;
    ll res = LLONG_MAX , sum = 0 ;
    rep(i,n){
        sum += A[i] + B[i] ;
        x-- ;
        ll c = x * B[i] ;
        chmin(res,c+sum) ;
        if(x == 0) break ;
    }
    cout << res << endl ;
}