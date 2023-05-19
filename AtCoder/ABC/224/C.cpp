#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll X[1010] , Y[1010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    ll ans = 0 ;
    rep(i,n) rrep(j,i+1,n) rrep(k,j+1,n){
        ll a = (X[j] - X[i]) * (Y[k] - Y[j]) ;
        ll b = (Y[j] - Y[i]) * (X[k] - X[j]) ;
        if(a != b) ans++;
    }
    cout << ans << endl;
}