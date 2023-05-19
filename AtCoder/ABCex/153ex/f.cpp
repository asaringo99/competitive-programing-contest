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

ll n , d , a ;
P X[202020] ;
ll S[202020] ;
vector<ll> vec ;

int main(){
    cin >> n >> d >> a ;
    rep(i,n) cin >> X[i].first >> X[i].second ;
    sort(X,X+n) ;
    ll res = 0 ;
    rep(i,n){
        auto it = lower_bound(vec.begin(),vec.end(),X[i].first-2*d) ;
        int id = it - vec.begin() ;
        vec.push_back(X[i].first) ;
        X[i].second -= S[i] - S[id] ;
        ll k = 0 ;
        if(X[i].second > 0) k = X[i].second % a == 0 ? X[i].second / a : X[i].second / a + 1 ;
        S[i+1] = S[i] + k * a ;
        res += k ;
    }
    cout << res << endl ;
}