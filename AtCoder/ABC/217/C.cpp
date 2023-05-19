#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
map<ll,ll> mp ;

int main(){
    cin >> n ;
    rep(i,n){
        int q ;
        cin >> q ;
        mp[q] = i + 1 ;
    }
    rrep(i,1,n+1) cout << mp[i] << " " ;
    cout << endl ;
}