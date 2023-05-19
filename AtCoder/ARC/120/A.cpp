#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

int main(){
    cin >> n ;
    ll sum = 0 , maxval = 0 , res = 0 ;
    for(int i = 0 ; i < n ; i++){
        ll a ; 
        cin >> a ;
        sum += a ;
        res += sum ;
        maxval = max(maxval,a) ;
        cout << maxval * (i + 1) + res << endl ;
    }
}