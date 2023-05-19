#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;

int main(){
    cin >> S ;
    if(S.size() == 4){
        int y = S[3] - '0' ;
        if(y <= 2) cout << S[0] << S[1] << '-' << endl ;
        else if(y <= 6) cout << S[0] << S[1] << endl ;
        else cout << S[0] << S[1] << '+' << endl ;
    }
    else{
        int y = S[2] - '0' ;
        if(y <= 2) cout << S[0] << '-' << endl ;
        else if(y <= 6) cout << S[0] << endl ;
        else cout << S[0] << '+' << endl ;
    }
}