#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , x ;
ll w[40] ;

ll f(){
    int k = n / 2 , m = n - k ;
    vector<ll> vec ;
    rep(S,1<<k){
        ll sum = 0 ;
        rep(i,k) if(S >> i & 1) sum += w[i] ;
        if(sum > x) continue ;
        vec.push_back(sum) ;
    }
    sort(vec.begin(),vec.end()) ;
    ll res = 0 ;
    rep(S,1<<m){
        ll sum = 0 ;
        rep(i,m) if(S >> i & 1) sum += w[k+i] ;
        if(sum > x) continue ;
        int num = upper_bound(vec.begin(),vec.end(),x-sum) - lower_bound(vec.begin(),vec.end(),x-sum) ;
        res += num ;
    }
    return res ;
}

int main(){
    cin >> n >> x ;
    rep(i,n) cin >> w[i] ;
    cout << f() << endl ;
}