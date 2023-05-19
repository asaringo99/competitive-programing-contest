#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    ll one = 0 , two = 0 , other = 0 ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        if(a == 1) one++ ;
        if(a == 2) two++ ;
    }
    cout << one * (one - 1) + 3 * one * two + (n - one) * (n - one - 1) / 2 + one * (n - two - one) * 2 << endl ;
}