#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[101010] , S[101010] ;
ll x ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    cin >> x ;
    rep(i,n) S[i+1] = S[i] + A[i] ;
    ll sum = S[n] ;
    ll tmp = x / sum ;
    ll res = tmp * n ;
    x -= sum * tmp ;
    rep(i,n){
        if(x < S[i]) break ;
        res++ ;
    }
    cout << res << endl ;
}