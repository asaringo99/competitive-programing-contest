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
ll A[101010] , S[202020] ;

bool f(ll x , int id){
    int id_1 = id ;
    auto it = lower_bound(S,S+2*n,S[id_1]+x) ;
    int id_2 = it - S ;
    x = S[id_2] - S[id_1] ;
    it = lower_bound(S,S+2*n,S[id_2]+x) ;
    int id_3 = it - S ;
    return S[id+n] - S[id_3] >= x ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,2*n) S[i+1] = S[i] + A[i%n] ;
    ll res = 0 ;
    rep(i,n){
        ll lef = 0 , rig = 1e18 ;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2 ;
            if(f(mid,i)) lef = mid ;
            else rig = mid ;
        }
        chmax(res,lef) ;
    }
    cout << res << endl ;
}