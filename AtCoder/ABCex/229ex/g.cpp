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

string T ;
int n ;
ll k ;
ll S[202020] , X[202020] ;
ll U[202020] , Y[202020] ;
vector<int> vec , arr ;

bool f(ll x){
    int m = vec.size() ;
    ll a , b ;
    if(x % 2 == 0) {
        a = x / 2 ;
        b = x / 2 - 1 ;
    }
    else {
        a = x / 2 ;
        b = x / 2 ;
    }
    bool ok = false ;
    rep(i,m){
        int l = i - b , r = i + a ;
        if(l < 0 || r >= m) continue;
        ll sum = X[vec[r]] - X[vec[i]] - a * S[vec[i]] ;
        ll mns = Y[n+1-vec[l]] - Y[n+1-vec[i]] - b * U[n+1-vec[i]] ;
        if(sum + mns <= k) ok = true ;
    }
    return ok ;
}

int main(){
    cin >> T >> k ;
    n = T.size() ;
    rep(i,n){
        U[i+1] = U[i] ;
        S[i+1] = S[i] ;
        if(T[i] == '.') S[i+1] += 1 ;
        if(T[n-1-i] == '.') U[i+1] += 1 ;
    }
    rep(i,n){
        X[i+1] = X[i] ;
        Y[i+1] = Y[i] ;
        if(T[i] == 'Y'){
            vec.push_back(i+1) ;
            X[i+1] += S[i+1] ;
        }
        if(T[n-1-i] == 'Y'){
            arr.push_back(n-i) ;
            Y[i+1] += U[i+1] ;
        }
    }
    ll lef = 0 , rig = 1e8 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) lef = mid ;
        else rig = mid ;
    }
    cout << lef << endl ;
}