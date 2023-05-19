#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P  ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
P A[202020] ;

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        A[i] = P(a,i+1) ;
    }
    sort(A,A+n) ;
    cout << A[n-2].second << endl ;
}