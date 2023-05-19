#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;
int n ;
set<string> st ;
map<P,int> mp ;

int A[100] , B[100] ;

int main(){
    cin >> S ;
    n = S.size() ;
    rep(i,n){
        A[i+1] = A[i] ;
        B[i+1] = B[i] ;
        if(S[i] == '0') A[i+1]++ ;
        if(S[i] == '1') B[i+1]++ ;
    }
    rep(i,n){
        string T = "" ;
        rrep(j,i,n){
            j
        }
    }
}