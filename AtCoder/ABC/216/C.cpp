#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n ;

int main(){
    cin >> n ;
    vector<char> vec ;
    while(n > 0){
        if(n % 2 == 1){
            n-- ;
            vec.push_back('A') ;
        }
        else{
            n /= 2 ;
            vec.push_back('B') ;
        }
    }
    rep(i,vec.size()) cout << vec[vec.size() - 1 - i] ;
    cout << endl ;
}