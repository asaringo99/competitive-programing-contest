#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    if(n * 108 / 100 < 206) cout << "Yay!" << endl ;
    else if(n * 108 / 100 > 206) cout << ":(" << endl ;
    else cout << "so-so" << endl ;
}