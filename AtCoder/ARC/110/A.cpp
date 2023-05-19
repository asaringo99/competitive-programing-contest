#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int N ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

ll lcm(ll a , ll b){
    return a / gcd(a,b) * b ;
}

int main(){
    cin >> N ;
    ll res = 1 ;
    for(int i = 1 ; i <= N ; i++){
        res = lcm(res,i) ;
    }
    cout << res + 1 << endl ;
}