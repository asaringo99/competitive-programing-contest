#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll a , b , c ;

int main(){
    cin >> a >> b >> c ;
    if(c % 2 == 0){
        if(abs(a) == abs(b)) cout << "=" << endl ;
        else if(abs(a) > abs(b)) cout << ">" << endl ;
        else cout << "<" << endl ;
    }
    else {
        if(a == b) cout << "=" << endl ;
        else if(a < b) cout << "<" << endl ;
        else  cout << ">" << endl ;
    }
}