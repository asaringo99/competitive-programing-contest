#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n ;

int main(){
    cin >> n ;
    int sum = 0 ;
    while(n / 2 > 0){
        sum++ ;
        n /= 2 ;
    }
    cout << sum << endl ;
}