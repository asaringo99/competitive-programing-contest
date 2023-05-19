#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll S , T ;

int main(){
    cin >> S >> T ;
    int res = 0 ;
    rep(i,101) rep(j,101) rep(k,101) if(i + j + k <= S && i * j * k <= T) res++ ;
    cout << res << endl ;
}