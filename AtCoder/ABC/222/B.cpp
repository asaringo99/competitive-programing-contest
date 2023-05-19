#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , p ;

int main(){
    cin >> n >> p ;
    int res = 0 ;
    rep(i,n){
        int a ;
        cin >> a ;
        if(a < p) res++ ;
    }
    cout << res << endl ;
}