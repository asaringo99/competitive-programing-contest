#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    if(n >= 212) cout << 8 << endl ;
    else if(n >= 126) cout << 6 << endl ;
    else cout << 4 << endl ;
}