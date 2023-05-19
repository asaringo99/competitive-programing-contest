#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll d , a , b ;

int main(){
    cin >> d >> a >> b ; // a - b
    if(a - b > 0) cout << b * d << endl ;
    else cout << a * d << endl ;
}