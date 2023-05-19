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

int n , m ;
ll X[202020] , Y[202020] ;

bool f(ll x){
    ll sx = X[0] , sy = Y[0] ;
    int cnt = 1 ;
    rep(i,m){
        if(X[i] - sx > x){
            cnt++ ;
            sx = X[i] ;
        }
    }
    cnt++ ;
    rep(i,m){
        if(Y[i] - sy > x){
            cnt++ ;
            sy = Y[i] ;
        }
    }
    return cnt <= n ;
}

int main(){
    cin >> n >> m ;
    rep(i,m)cin >> X[i] >> Y[i] ;
    sort(X,X+m) ;
    sort(Y,Y+m) ;
    ll lef = -1 , rig = 1e10 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}