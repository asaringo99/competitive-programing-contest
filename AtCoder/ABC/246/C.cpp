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

ll n , k , x ;
ll A[202020] ;

int main(){
    fast_input_output
    cin >> n >> k >> x ;
    ll res = 0 ;
    rep(i,n) cin >> A[i] , res += A[i] ;
    sort(A,A+n,greater<ll>()) ;
    ll sum = 0 ;
    rep(i,n){
        ll c = A[i] / x ;
        if(c > k) {
            sum += x * k ;
            cout << res - sum << endl ;
            return 0 ;
        }
        sum += x * c ;
        A[i] -= c * x ;
        k -= c ;
    }
    sort(A,A+n,greater<ll>()) ;
    rep(i,n){
        if(k == 0) break ;
        sum += A[i] ;
        k-- ;
    }
    cout << res - sum << endl ;
}