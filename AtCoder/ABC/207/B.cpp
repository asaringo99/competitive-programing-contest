#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int a , b , c , d ;

int main(){
    cin >> a >> b >> c >> d ;
    if(c * d - b <= 0) cout << -1 << endl ;
    else {
        int val = a / (c * d - b) ;
        if(a % (c * d - b) != 0) val++ ;
        cout << val << endl ;
    }
}