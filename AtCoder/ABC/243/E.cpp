#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
ll d[303][303] , e[303][303] ;
map<P,bool> mp , used ;
int res = 0 ;

void f(){
    rep(k,n) rep(i,n) rep(j,n) if(d[i][j] >= d[i][k] + d[k][j]){
        d[i][j] = d[i][k] + d[k][j] ;
        if(mp[P(i,j)] && !used[P(i,j)] && i != k && k != j) {
            res++ ;
            used[P(i,j)] = true ;
            used[P(j,i)] = true ;
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,n) rep(j,n) {
        d[i][j] = 1e16 ;
        if(i == j) d[i][j] = 0 ;
    }
    rep(i,m){
        ll a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        d[a][b] = c ;
        d[b][a] = c ;
        e[a][b] = c ;
        e[b][a] = c ;
        mp[P(a,b)] = true ;
        mp[P(b,a)] = true ;
    }
    f() ;
    cout << res << endl ;
}