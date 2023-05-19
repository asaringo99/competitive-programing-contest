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
char C[1010][1010] ;

int main(){
    cin >> n ;
    rep(i,n){
        rep(j,n) cin >> C[i][j] ;
    }
    bool ok = false ;
    rep(i,n){
        rep(j,n){
            if(j + 5 >= n) continue ;
            int x = 0 ;
            rep(k,6) if(C[i][j+k] == '#') x++ ;
            if(x >= 4) ok = true ;
        }
    }
    rep(i,n){
        rep(j,n){
            if(i + 5 >= n) continue ;
            int x = 0 ;
            rep(k,6) if(C[i+k][j] == '#') x++ ;
            if(x >= 4) ok = true ;
        }
    }
    rep(i,n){
        rep(j,n){
            if(i + 5 >= n) continue ;
            if(j + 5 >= n) continue ;
            int x = 0 ;
            rep(k,6) if(C[i+k][j+k] == '#') x++ ;
            if(x >= 4) ok = true ;
        }
    }
    rep(i,n){
        rep(j,n){
            if(i - 5 < 0) continue ;
            if(j + 5 >= n) continue ;
            int x = 0 ;
            rep(k,6) if(C[i-k][j+k] == '#') x++ ;
            if(x >= 4) ok = true ;
        }
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}