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
P A[101010] ;
ll res[101010] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        int a ;
        cin >> a ;
        A[i] = P(a,i) ;
    }
    A[n] = P(0,-1) ;
    sort(A,A+n+1) ;
    int d = n+1 ;
    ll count = 0 ;
    int i = n ;
    while(i > 0){
        auto [a,id] = A[i] ;
        auto it = lower_bound(A,A+n+1,P(a,-1)) ;
        auto [c,k] = *it ; it-- ;
        auto [b,j] = *it ;
        ll sum = upper_bound(A,A+n+1,P(a,1e10)) - lower_bound(A,A+n+1,P(a,-1)) ;
        i -= sum ;
        count += sum ;
        chmin(d,(int)k) ;
        res[d] += count * (ll)(a - b) ;
    }
    rep(i,n) cout << res[i] << endl ;
}