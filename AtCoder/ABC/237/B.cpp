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

int H , W ;

int main(){
    cin >> H >> W ;
    vector<vector<int>> vec(H,vector<int>(W)) ;
    rep(i,H) rep(j,W) cin >> vec[i][j] ;
    rep(i,W) {
        rep(j,H) cout << vec[j][i] << " " ; cout << endl ;
    }
}