#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

ll n , k ;

int main(){
    cin >> n >> k ;
    P A[n] ;
    for(int i = 0 ; i < n ; i++) cin >> A[i].first >> A[i].second ;
    sort(A,A+n) ;
    for(int i = 0 ; i < n ; i++){
        if(k < A[i].first){
            cout << k << endl ;
            return 0 ;
        }
        k += A[i].second ;
    }
    cout << k << endl ;
}