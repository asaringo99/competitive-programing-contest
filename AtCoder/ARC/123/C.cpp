#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int t ;

int main(){
    cin >> t ;
    rep(i,t){
        string S ;
        cin >> S ;

        // 0を含む
        bool zero = false ;
        for(char u : S) if(u == '0') zero = true ;
        if(zero){
            cout << 4 << endl ;
            continue ;
        }

        reverse(S.begin() , S.end()) ;
        // 1を含む
        bool one = false , ko = false ;
        for(char u : S){
            if(u == '1') one = true ;
            if(u - '0' > 3 && one) ko = true ;
        }
        if(ko){
            cout << 4 << endl ;
            continue ;
        }

        // 2を含む
        bool two = false ;
        for(char u : S){
            if(u == '2') two = true ;
            if(u - '0' > 6 && two) ko = true ;
        }
        if(ko){
            cout << 4 << endl ;
            continue ;
        }

        int count = 1 ;
        for(char u : S){
            if(u - '0' > 3) count = max(count,2) ;
            if(u - '0' > 6) count = max(count,3) ;
        }
        cout << count << endl ;
    }
}