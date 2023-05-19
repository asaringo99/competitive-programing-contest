#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n ;
vector<int> ans ;

int main(){
    cin >> n ;
    ll x = 1 , y = 1 ;
    int count = 127 ;
    cout << 1 << endl ;
    cout << 2 << endl ;
    while(true){
        if(n / y + n % y <= count){
            for(int i = 0 ; i < n / y ; i++) ans.push_back(3) ;
            for(int i = 0 ; i < n % y ; i++) ans.push_back(1) ;
        }
    }
}