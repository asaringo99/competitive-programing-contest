#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll n , k ;

ll combination1(ll n){
    return (n - 2) * (n - 1) / 2 ;
}
ll combination2(ll n){
    return n + 1 ;
}

int main(){
    cin >> n >> k ;
    ll sum = 0 ;
    ll val = 1 ;
    while(true){
        ll pls = val * val * val ;
        if(sum + pls > k) break ;
        sum = pls ;
        val++ ;
    }
    ll i = 1 ;
    cout << val << endl ;
    while(i < val){
        ll pls = val * val - 1 ;
        if(sum + pls > k) break ;
        sum += pls ;
        i++ ;
    }
    ll j = k - sum ;
    ll a = val - i - j ;
    cout << i << " " << j << " " << a << endl ;
    cout << val << endl ;
}