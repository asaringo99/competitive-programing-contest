#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

ll n , k ;
ll A[507] ;
vector<ll> divisor ;

int main(){
    cin >> n >> k ;
    ll GCD = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
        GCD += A[i] ;
    }
    for(ll i = 1 ; i * i <= GCD ; i++){
        if(GCD % i == 0){
            divisor.push_back(i) ;
            if(i * i != GCD) divisor.push_back(GCD / i) ;
        }
    }
    sort(divisor.begin() , divisor.end() , greater<int>()) ;
    ll m = divisor.size() ;
    for(int i = 0 ; i < m ; i++){
        ll div = divisor[i] ;
        vector<ll> mod ;
        for(int j = 0 ; j < n ; j++) mod.push_back(A[j] % div) ;
        sort(mod.begin(),mod.end()) ;
        ll R[n+1] , U[n+1] ;
        R[0] = 0 ;
        U[0] = 0 ;
        for(int j = 0 ; j < n ; j++){
            R[j+1] = R[j] + mod[j] ;
            U[j+1] = U[j] + div - mod[j] ;
        }
        ll sum = LLONG_MAX ;
        for(int j = 1 ; j <= n ; j++){
            ll val = max(R[j] , U[n] - U[j]) ;
            sum = min(sum,val) ;
        }
        if(sum <= k){
            cout << div << endl ;
            return 0 ;
        }
    }
}