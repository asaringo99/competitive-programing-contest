#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

string S ;

int main(){
    cin >> S ;
    map<char,char> rem ;
    rem['0'] = '0' ;
    rem['1'] = '1' ;
    rem['6'] = '9' ;
    rem['8'] = '8' ;
    rem['9'] = '6' ;
    int n = S.size() ;
    for(int i = n - 1 ; i >= 0 ; i--){
        cout << rem[S[i]] ;
    }
    cout << endl ;
}