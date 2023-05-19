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

int n , m , h , k ;
P X[101010] ;
vector<int> vec ;
vector<TP> H ;
ll A[1010] ;
ll S[1010] ;

int main(){
    cin >> n >> m >> h >> k ;
    rep(i,n) cin >> A[i] ;
    rep(i,m){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        H.push_back({y,x,i}) ;
    }
    sort(H.begin(),H.end()) ;
    rep(i,n) vec.push_back(i) ;
    for(TP tp : H){
        auto [y,x,i] = tp ;
        int u = x , v = x + 1 ;
        X[i] = P(vec[u],vec[v]) ;
        swap(vec[u],vec[v]) ;
    }
    ll res = 0 ;
    rep(i,n) {
        if(vec[i] < k) res += A[i] ;
        S[vec[i]] = A[i] ;
    }
    ll ans = res ;
    rep(i,m){
        auto[u,v] = X[i] ;
        if(u < k && v < k) continue;
        if(u >= k && v >= k) continue;
        if(u < k) chmin(ans,res-S[u]+S[v]) ;
        else chmin(ans,res-S[v]+S[u]) ;
    }
    cout << ans << endl ;
}