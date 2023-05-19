#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int a , b ;

map<int,int> rem ;

int main(){
    cin >> a >> b ;
    for(int i = 1 ; i <= b ; i++){
        rem[i] = b / i - (a - 1) / i ;
    }
    int res = 1 ;
    for(int i = 1 ; i <= b ; i++){
        if(rem[i] >= 2) res = i ;
    }
    cout << res << endl ;
}