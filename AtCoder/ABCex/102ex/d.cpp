#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[202020] , S[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    S[0] = A[0] ;
    rrep(i,1,n) S[i] = S[i-1] + A[i] ;
    ll res = 1e18 ;
    rrep(i,2,n-1){
        auto ft = lower_bound(S,S+n,S[i-1]/2) ;
        ll l1 = *ft , l2 = S[i-1] - l1 ; ft-- ;
        ll l3 = *ft , l4 = S[i-1] - l3 ;
        if(abs(l1-l2) > abs(l3-l4)) l1 = l3 , l2 = l4 ;
        ll v = (S[n-1] - S[i-1]) / 2 ;
        auto lt = lower_bound(S,S+n,S[i-1]+v) ;
        ll r1 = *lt - S[i-1] , r2 = S[n-1] - r1 - S[i-1] ; lt-- ;
        ll r3 = *lt - S[i-1] , r4 = S[n-1] - r3 - S[i-1] ;
        if(abs(r1-r2) > abs(r3-r4)) r1 = r3 , r2 = r4 ;
        res = min(res,max({l1,l2,r1,r2})-min({l1,l2,r1,r2})) ;
    }
    cout << res << endl ;
}