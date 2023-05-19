#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
string S ;

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n >> S ;
    ll res = 0 ;
    rep(i,n){
        if(S[i] == 'b') res += powll(2,i) ;
        if(S[i] == 'c') res += 2LL * powll(2,i) ;
    }
    cout << res << endl ;
}