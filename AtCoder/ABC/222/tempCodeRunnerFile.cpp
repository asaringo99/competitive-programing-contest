#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string n ;

int main(){
    cin >> n ;
    if(n.size() == 1) cout << "000" << n << endl ;
    if(n.size() == 2) cout << "00" << n << endl ;
    if(n.size() == 3) cout << "0" << n << endl ;
    if(n.size() == 4) cout << n << endl ;
}