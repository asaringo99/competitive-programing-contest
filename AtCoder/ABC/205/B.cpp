#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
set<int> S ;

int main(){
    cin >> n ;
    bool ok = true ;
    rep(i,n){
        int a ;
        cin >> a ;
        if(S.count(a) == 1){
            ok = false ;
        }
        S.insert(a) ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}