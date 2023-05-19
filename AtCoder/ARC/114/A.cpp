#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

vector<ll> cal(ll n){
    vector<ll> res ;
    for(int i = 2 ; i * i <= n ; i++){
        if(n % i != 0) continue ;
        while(n % i == 0){
            n /= i ;
        }
        res.push_back(i);
    }
    if(n != 1) res.push_back(n) ;
    sort(res.begin() , res.end()) ;
    return res ;
}

int main(){
    cin >> n ;
    ll X[n] ;
    set<ll> S ;
    for(int i = 0 ; i < n ; i++){
        int x ;
        cin >> x ;
        X[i] = x ;
        vector<ll> pes = cal(x) ;
        for(ll u : pes){
            S.insert(u) ;
        }
    }
    vector<ll> prime ;
    for(ll u : S){
        prime.push_back(u) ;
    }

    ll ans = LLONG_MAX ;
    int N = prime.size() ;
    for(int i = 0 ; i < (1 << N) ; i++){
        ll pes = 1 ;
        for(int j = 0 ; j < N ; j++){
            if(i >> j & 1) pes *= prime[j] ;
        }
        bool ok = true ;
        for(int j = 0 ; j < n ; j++){
            if(gcd(X[j],pes) == 1) ok = false ;
        }
        if(ok) ans = min(ans,pes) ;
    }
    cout << ans << endl ;
}