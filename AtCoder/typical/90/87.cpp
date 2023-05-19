#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , p , k ;
vector<vector<ll>> d(50,vector<ll>(50,-1)) , dist(50,vector<ll>(50,-1)) ;

void warshall_floyd(){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

ll f(ll x){
    d = dist ;
    ll res = 0 ;
    rep(i,n) rep(j,n) if(d[i][j] == -1) d[i][j] = x ;
    warshall_floyd() ;
    rep(i,n) rep(j,n) if(i < j && d[i][j] <= p) res++ ;
    return res ;
}

int main(){
    cin >> n >> p >> k ;
    rep(i,n) rep(j,n) cin >> dist[i][j] ;
    ll R = -1 , L = (ll)1e18 ;
    ll lef = 0 , rig = (ll)1e18 ;
    while(rig - lef > 1){
        ll m = (lef + rig) / 2 ;
        // cout << lef << " " << rig << " " << f(m) << endl ;
        if(f(m) == k) lef = m ;
        if(f(m) < k) rig = m ;
        if(f(m) > k) lef = m ;
    }
    R = lef ;
    lef = 0 , rig = (ll)1e18 ;
    while(rig - lef > 1){
        ll m = (lef + rig) / 2 ;
        if(f(m) == k) rig = m ;
        if(f(m) < k) rig = m ;
        if(f(m) > k) lef = m ;
    }
    L = rig ;
    if(L > (ll)9e17){
        cout << 0 << endl ;
        return 0 ;
    }
    if(R > (ll)9e17) {
        cout << "Infinity" << endl ;
        return 0 ;
    }
    // while(f(R+1) == k) R++ ;
    // while(L - 1 > 0 && f(L-1) == k) L-- ;
    if(R == 0 || f(R) != k || f(L) != k) cout << 0 << endl ;
    else cout << R - L + 1 << endl ;
}