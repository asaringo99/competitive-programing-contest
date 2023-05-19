#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int  A[101010] , X[101010] ;
set<int> st ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    memset(X,-1,sizeof(X)) ;
    int y = (n - 1) / 2 ;
    cout << y << endl ;
    int j = 1 ;
    for(int i = 0 ; i < y ; i++){
        X[j] = A[i] ;
        j += 2 ;
        st.insert(A[i]) ;
    }
    int i = 0 ;
    j = 0 ;
    while(i < n){
        if(X[i] != -1){
            i++ ;
            continue ;
        }
        if(st.count(A[j])){
            j++ ;
            continue ;
        }
        X[i] = A[j] ;
    }
    rep(i,n) cout << X[i] << " " ;
    cout << endl ;
}