#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , t ;

int main(){
    cin >> n ;
    rep(i,n){
        string s ;
        cin >> t >> s ;
        bool odd = true ;
        if(t % 2 == 0) odd = false ;
        bool raze ;
        if(odd) {
            raze = false ;
            for(int j = 0 ; j < t ; j += 2) if((s[j] - '0') % 2 == 1) raze = true ;
        }
        else {
            raze = true ;
            for(int j = 1 ; j < t ; j += 2) if((s[j] - '0') % 2 == 0) raze = false ;
        }
        if(raze) cout << 1 << endl ;
        else cout << 2 << endl ;
    }
}