#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
map<int,ll> mp ;

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        mp[a]++ ;
    }
    ll res = 0 ;
    for(auto it : mp){
        res += it.second * (n - it.second) ;
    }
    cout << res / 2 << endl ;
}