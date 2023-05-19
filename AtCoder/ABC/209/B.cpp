#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , x ;
int A[200] ;

int main(){
    cin >> n >> x ;
    ll sum = 0 ;
    rep(i,n) {
        cin >> A[i] ;
        if(i % 2 == 1) A[i]-- ;
        sum += A[i] ;
    }
    if(sum <= x) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}