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
int a , b , c ;
bool use[1010] ;
int X[1010] , Y[1010] , Z[1010] , T[1010] ;
int res[1010] ;

int main(){
    cin >> a >> b >> c >> n ;
    rep(i,a+b+c) res[i] = 2 ;
    rep(i,n){
        int x , y , z , t ;
        cin >> x >> y >> z >> t ;
        x-- ; y-- ; z-- ;
        X[i] = x ;
        Y[i] = y ;
        Z[i] = z ;
        T[i] = t ;
        if(t == 1){
            use[x] = true ;
            use[y] = true ;
            use[z] = true ;
            res[x] = 1 ;
            res[y] = 1 ;
            res[z] = 1 ;
        }
    }
    rep(i,n){
        int x = X[i] , y = Y[i] , z = Z[i] ;
        if(T[i] == 0){
            if(use[x] && use[y]) res[z] = 0 ;
            if(use[x] && use[z]) res[y] = 0 ;
            if(use[y] && use[z]) res[x] = 0 ;
        }
    }
    rep(i,a+b+c) cout << res[i] << endl ;
}