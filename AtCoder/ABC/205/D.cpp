#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
ll A[100007] ;

const ll INF = 1e18+1e10 ;

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    rep(i,q){
        ll k ;
        cin >> k ;
        ll lef = 0 , rig = INF ;
        while(rig - lef > 0){
            ll m = (lef + rig) / 2 ;
            auto it = upper_bound(A,A+n,m) ;
            int num = it - A ;
            if(m - num >= k) rig = m ;
            else lef = m + 1 ;
        }
        cout << rig << endl ;
    }
}