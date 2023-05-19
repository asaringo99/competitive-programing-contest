#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
string S ;

int main(){
    cin >> n >> S ;
    if(S[(n-1)%7] == 'x') cout << "No" << endl;
    else cout << "Yes" << endl;
}