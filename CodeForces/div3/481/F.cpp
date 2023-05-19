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

int n , k ;
vector<int> G[202020] ;
P X[202020] ;
ll Y[202020] ;
int ans[202020] ;

int main(){
    cin >> n >> k ;
    rep(i,n){
        int x ;
        cin >> x ;
        X[i] = P(x,i) ;
        Y[i] = x ;
    }
    rep(i,k){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    sort(X,X+n) ;
    rep(i,n){
        int v = X[i].first , id = X[i].second ;
        ll res = lower_bound(X,X+n,P(v,-1)) - X ;
        for(int u : G[id]) if(Y[u] < v) res-- ;
        ans[id] = res ;
    }
    rep(i,n) cout << ans[i] << " " ; cout << endl ;
}