#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int a , b ;

int main(){
    cin >> a >> b ;
    int c = a - b ;
    ll res = 1 ;
    for(int i = 0 ; i < c ; i++) res *= 32 ;
    cout << res << endl ;
}