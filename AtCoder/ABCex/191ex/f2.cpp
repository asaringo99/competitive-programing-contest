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

int n ;
ll A[2020] ;
map<ll,ll> dp ;
vector<int> vec[2020] ;

int main(){
    cin >> n ;
    ll minval = 1e10 ;
    rep(i,n) cin >> A[i] , chmin(minval,A[i]) ;
    dp[minval] = minval ;
    rep(i,n){
        int a = A[i] ;
        for(ll x = 1 ; x * x <= a ; x++){
            if(a % x == 0){
                vec[i].push_back(x) ;
                if(x * x != a) vec[i].push_back(a/x) ;
            }
        }
    }
    rep(i,n){
        for(int u : vec[i]) dp[u] = gcd(dp[u],A[i]) ;
    }
    ll res = 0 ;
    for(auto it : dp) if(it.first <= minval) if(it.second == it.first) res++ ;
    cout << res << endl ;
}