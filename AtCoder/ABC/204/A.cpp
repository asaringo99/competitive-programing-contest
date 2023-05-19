#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int x , y ;

int main(){
    cin >> x >> y ;
    if(x == y) {
        cout << x << endl ;
        return 0 ;
    }
    if(x + y == 1) cout << 2 << endl ;
    if(x + y == 2) cout << 1 << endl ;
    if(x + y == 3) cout << 0 << endl ;
}