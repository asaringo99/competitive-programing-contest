#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int a , b , c ;

int main(){
    cin >> a >> b >> c ;
    if(a % c == 0) cout << a << endl ;
    else{
        if(a / c * c + c <= b) cout << a / c * c + c << endl ;
        else cout << -1 << endl ;
    }
}