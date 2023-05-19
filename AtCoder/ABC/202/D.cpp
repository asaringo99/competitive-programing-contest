#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int a , b ;
ll k ;


ll combination(ll n , ll r) {
    ll tes[61] ;
    tes[0] = 1 ;
    tes[1] = n ;
    for(int i = 2 ; i <= n ; i++){
        tes[i] = tes[i-1] * (n - i + 1) / i ;
    }
    return tes[r] ;
}

int main(){
    cin >> a >> b >> k ;
    vector<char> res ;
    int n = a + b ;
    for(int i = 1 ; i <= n ; i++){
        if(a == 0){
            res.push_back('b') ;
            continue ;
        }
        if(combination(n - i , a - 1) < k){
            res.push_back('b') ;
            k -= combination(n - i , a - 1) ;
        }
        else{
            res.push_back('a') ;
            a-- ;
        }
    }
    for(char u : res) cout << u ;
    cout << endl ;
}