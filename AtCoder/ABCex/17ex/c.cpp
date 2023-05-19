#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
ll S[101010] ;
ll imos[101010] ;

int main(){
    cin >> n >> m ;
    ll sum = 0 ;
    rep(i,n){
        int l , r , c ;
        cin >> l >> r >> c ;
        S[l] += c ;
        S[r+1] -= c ;
        sum += c ;
    }
    ll s = 0 ;
    rep(i,m+1){
        s += S[i] ;
        imos[i] = s ;
    }
    ll res = 0 ;
    rrep(i,1,m+1){
        res = max(res,sum-imos[i]) ;
    }
    cout << res << endl ;
}