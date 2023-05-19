#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ; 
ll A[202020] ;

bool f(ll x){
    ll rem = 0 ;
    rep(i,n){
        if(A[i] + rem < x) return false ;
        rem = A[i] + rem - x ;
    }
    return true ;
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    ll lef = 0 , rig = 1e9 + 10 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) lef = mid ;
        else rig = mid ;
    }
    cout << lef / m << endl ;
}