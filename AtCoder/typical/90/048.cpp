#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
vector<ll> X ;

int main(){
    cin >> n >> k ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        X.push_back(b) ;
        X.push_back(a - b) ;
    }
    sort(X.begin(),X.end(),greater<ll>()) ;
    ll res = 0 ;
    rep(i,k) res += X[i] ;
    cout << res << endl ;
}