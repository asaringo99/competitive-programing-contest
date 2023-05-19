#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , k ;

int main(){
    cin >> n >> k ;
    ll res = 0 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= k ; j++){
            res += i * 100  + j ;
        }
    }
    cout << res << endl ;
}