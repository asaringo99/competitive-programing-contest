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

ll n , m ;
ll A[303030] , B[303030] ;

bool f(ll x){
    ll sum_a = 0 , sum_b = 0 ;
    rep(i,n){
        ll val = x ;
        ll a = A[i] , b = B[i] ;
        ll cnt_a = val / a ;
        if(val % a != 0) cnt_a++ ;
        if(cnt_a > m) cnt_a = m ;
        sum_a += cnt_a ;
        val -= cnt_a * a ;
        if(val <= 0) continue;
        ll cnt_b = val / b ;
        if(val % b != 0) cnt_b++ ;
        sum_b += cnt_b ;
        if(sum_a + sum_b > n * m) return false ;
    }
    return sum_a + sum_b <= n * m ;
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rep(i,n) chmax(A[i],B[i]) ;
    ll lef = 0 , rig = 2e18 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) lef = mid ;
        else rig = mid ;
    }
    cout << lef << endl ;
}