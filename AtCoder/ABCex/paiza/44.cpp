#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,int> P ;
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
string T ;
ll A[202020] , S[202020] ;

bool f(ll x , int s){
    auto it = lower_bound(S,S+2*n+1,S[s]+x) ;
    int j = it - S ;
    if(j > s + n) return false ;
    auto jt = lower_bound(S,S+2*n+1,S[j]+x) ;
    int k = jt - S ;
    if(k > s + n) return false ;
    ll val = S[s+n] - S[k] ;
    return val >= x ;
}

ll g(ll x , int s){
    auto it = lower_bound(S,S+2*n+1,S[s]+x) ;
    int j = it - S ;
    if(j > s + n) return false ;
    auto jt = lower_bound(S,S+2*n+1,S[j]+x) ;
    int k = jt - S ;
    if(k > s + n) return false ;
    ll val1 = S[j] - S[s] ;
    ll val2 = S[k] - S[j] ;
    ll val3 = S[s+n] - S[k] ;
    return max({val1,val2,val3}) - min({val1,val2,val3}) ;
}
int main(){
    fast_input_output
    cin >> n >> T ;
    rep(i,n) A[i] = T[i] - '0' ;
    rep(i,n) A[i+n] = T[i] - '0' ;
    rep(i,2*n) S[i+1] = S[i] + A[i] ;
    ll res = 1e16 ;
    rep(i,n){
        ll lef = 0 , rig = 1e7 ;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2 ;
            if(f(mid,i)) lef = mid ;
            else rig = mid ;
        }
        chmin(res,g(lef,i)) ;
    }
    cout << res << endl ;
}