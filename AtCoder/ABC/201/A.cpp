#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main(){
    int A[3] ;
    for(int i = 0 ; i < 3 ; i++) cin >> A[i] ;
    sort(A,A+3) ;
    if(A[2] - A[1] == A[1] - A[0]) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}