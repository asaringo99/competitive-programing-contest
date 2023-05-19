#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    if(S.size() >= 3){
        if(S[n-3] == 'i' && S[n-2] == 's' && S[n-1] == 't') cout << "ist" << endl ;
    }
    else cout << "er" << endl ;
} 