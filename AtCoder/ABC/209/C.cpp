#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

map<int,int> mp ;

int n ;
ll C[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> C[i] ;
    sort(C,C+n) ;
    ll cnt = 0 ;
    ll sum = 1 ;
    rep(i,n){
        sum *= (C[i] - cnt) ;
        sum %= mod ;
        cnt++ ;
    }
    cout << sum << endl ;
}