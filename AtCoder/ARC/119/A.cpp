#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

ll n ;

int main(){
    cin >> n ;
    ll sum = INT_MAX ;
    rep(i,61){
        ll val = pow(2,i) ;
        sum = min(sum,i + n / val + n % val) ;
    }
    cout << sum << endl ;
}