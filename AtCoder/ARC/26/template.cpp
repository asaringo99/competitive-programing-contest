#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
P A[101010] ;

P f(ll x){
    ll sum = 0 , res = 0 ;
    rep(i,n){
        if(sum > 1e12) return P(1e12,1e18) ;
        ll a = A[i].first , d = A[i].second ;
        if(x - a < 0) continue ;
        ll y = (x - a) / d + 1 ;
        sum += y ;
        res += a * y + (y - 1) * y / 2 * d ;
    }
    return P(sum,res) ;
}

int main(){
    cin >> k >> n ;
    rep(i,n) cin >> A[i].first >> A[i].second ;
    ll lef = 0 , rig = 1e12 , res = 1e18 , sum = 0 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        P p = f(mid) ;
        ll cnt = p.first ;
        if(cnt < k) lef = mid ;
        else{
            rig = mid ;
            sum = cnt ;
            res = p.second ;
        }
    }
    cout << res - rig * (sum - k) << endl ;
}