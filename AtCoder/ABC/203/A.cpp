#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int a , b , c ;

int main(){
    cin >> a >> b >> c ;
    if(a == b) cout << c << endl ;
    else if(b == c) cout << a << endl ;
    else if(a == c) cout << b << endl ;
    else cout << 0 << endl ;
}