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

int H , W , n ;

ll X[101010] , Y[101010] ;
P Z[101010] ;
ll ans[4] ;
ll mval[4] ;

int main(){
    cin >> H >> W >> n ;
    rep(i,n) cin >> X[i] >> Y[i] , Z[i] = P(X[i],Y[i]) ;
    sort(X,X+n) ;
    sort(Y,Y+n) ;
    ll dx[4] = {(n-1)/2,(n-1)/2,n/2,n/2} ;
    ll dy[4] = {(n-1)/2,n/2,(n-1)/2,n/2} ;
    rep(i,n) {
        auto[xx,yy] = Z[i] ;
        rep(j,4){
            ans[j] += abs(X[dx[j]]-xx) + abs(Y[dy[j]]-yy) ;
            chmax(mval[j],abs(X[dx[j]]-xx) + abs(Y[dy[j]]-yy)) ;
        }
    }
    ll val = LLONG_MAX ;
    int ex , ey ;
    rep(i,4) {
        ans[i] *= 2 ;
        ans[i] -= mval[i] ;
        if(val > ans[i]){
            val = ans[i] ;
            ex = X[dx[i]] ;
            ey = Y[dy[i]] ;
        }
    }
    cout << val << endl ;
    cout << ex << " " << ey << endl ;
}