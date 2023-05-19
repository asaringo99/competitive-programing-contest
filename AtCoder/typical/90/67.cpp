#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string n ;
int k ;

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

ll eight_to_ten(string x){
    ll res = 0 ;
    int m = x.size() ;
    for(int i = 0 ; i < m ; i++){
        res += (x[i] - '0') * powll(8,m-1-i) ;
    }
    return res ;
}

string ten_to_nine(ll x){
    string res = "" ;
    while(x > 0){
        int mod = x % 9 ;
        if(mod == 8) mod = 5 ;
        res += (mod + '0') ;
        x /= 9 ;
    }
    reverse(res.begin(),res.end()) ;
    return res ;
}

string solver(string n , ll k){
    for(int i = 0 ; i < k ; i++){
        ll x = eight_to_ten(n) ;
        n = ten_to_nine(x) ;
    }
    if(n == "") n = "0" ;
    return n ;
}

int main(){
    cin >> n >> k ;
    cout << solver(n,k) << endl ;
    string SS ;
    cout << SS << endl ;
}