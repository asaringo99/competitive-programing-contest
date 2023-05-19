#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , k ;
P A[200007] ;
ll B[200007] ;

int main(){
    cin >> n >> k ;
    rep(i,n) {
        cin >> A[i].first ;
        A[i].second = i ;
    }
    sort(A,A+n) ;
    ll common = k / n , bias = k % n ;
    rep(i,n){
        if(i < bias) B[A[i].second] = common + 1 ;
        else B[A[i].second] = common ;
    }
    rep(i,n) cout << B[i] << endl ;
}