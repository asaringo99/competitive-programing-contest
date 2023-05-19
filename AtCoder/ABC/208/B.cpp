#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int per[11] ;

void f(){
    per[1] = 1 ;
    rrep(i,1,10) per[i+1] = per[i] * (i + 1) ;
}

int main(){
    cin >> n ;
    f() ;
    int res = 0 ;
    for(int i = 10 ; i >= 1 ; i--){
        while(n >= per[i]) {
            n -= per[i] ;
            res++ ;
        }
    }
    cout << res << endl ;
}