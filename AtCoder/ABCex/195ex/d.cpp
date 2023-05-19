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

int n , m , q ;
P W[101] ;
int X[101] ;

int main(){
    cin >> n >> m >> q ;
    rep(i,n) cin >> W[i].second >> W[i].first ;
    rep(i,m) cin >> X[i] ;
    sort(W,W+n,greater<>()) ;
    rep(z,q){
        int l , r ;
        cin >> l >> r ;
        l-- ; r-- ;
        vector<int> Y ;
        rep(i,m) if(l > i || i > r) Y.push_back(X[i]) ;
        sort(Y.begin(),Y.end()) ;
        int k = Y.size() ;
        vector<bool> used(k,false) ;
        ll sum = 0 ;
        rep(i,n){
            rep(j,k){
                if(Y[j] < W[i].second || used[j]) continue ;
                used[j] = true ;
                sum += W[i].first ; 
                break ;
            }
        }
        cout << sum << endl ;
    }
}