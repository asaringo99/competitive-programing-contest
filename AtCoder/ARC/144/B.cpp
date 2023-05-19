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

ll n , a , b ;
ll A[303030] ;

bool f(ll x){
    ll cnt = 0 ;
    rep(i,n){
        if(x <= A[i]){
            ll d = A[i] - x ;
            d /= b ;
            cnt += d ;
        }
        else{
            ll d = x - A[i] ;
            ll y = d / a ;
            if(d % a != 0) y++ ;
            cnt -= y ;
        }
    }
    return cnt >= 0 ;
}

int main(){
    fast_input_output
    cin >> n >> a >> b ;
    rep(i,n) cin >> A[i] ;
    ll lef = 0 , rig = 1e10 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) lef = mid ;
        else rig = mid ;
    }
    cout << lef << endl ;
}