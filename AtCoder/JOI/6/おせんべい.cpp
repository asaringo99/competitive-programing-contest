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

int r , c ;
int C[12][10101] ;

int main(){
    cin >> r >> c ;
    rep(i,r) rep(j,c) cin >> C[i][j] ;
    ll res = 0 ;
    rep(S,1<<r){
        vector<int> vec ;
        rep(i,r) if(S >> i & 1) vec.push_back(i) ;
        ll sum = 0 ;
        rep(i,c){
            ll x = 0 , y = 0 ;
            rep(j,r){
                if(C[j][i] == 0) x++ ;
                if(C[j][i] == 1) y++ ;
            }
            for(int u : vec){
                if(C[u][i] == 0) x-- , y++ ;
                if(C[u][i] == 1) x++ , y-- ;
            }
            sum += max(x,y) ;
        }
        chmax(res,sum) ;
    }
    cout << res << endl ;
}