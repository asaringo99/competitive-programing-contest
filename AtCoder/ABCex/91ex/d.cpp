#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[202020] , B[202020] , X[202020] , Y[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    ll res = 0 ;
    rep(i,29){
        int bit = 1 << i + 1 , cit = 1 << i ;
        rep(j,n) X[j] = A[j] & (bit - 1) ;
        rep(j,n) Y[j] = B[j] & (bit - 1) ;
        ll sum = 0 ;
        sort(Y,Y+n) ;
        rep(i,n){
            auto it = lower_bound(Y,Y+n,cit-X[i]) ;
            auto jt = lower_bound(Y,Y+n,bit-X[i]) ;
            sum += jt - it ;
        }
        cit *= 3 ;
        bit *= 2 ;
        rep(i,n){
            auto it = lower_bound(Y,Y+n,cit-X[i]) ;
            auto jt = lower_bound(Y,Y+n,bit-X[i]) ;
            sum += jt - it ;
        }
        if(sum % 2 == 1) res |= 1 << i ;
    }
    cout << res << endl ;
}