#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<string,string> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
map<P,bool> mp ;

int main(){
    cin >> n ;
    bool ok = false ;
    rep(i,n){
        string S , T ;
        cin >> S >> T ;
        if(mp[P(S,T)]) ok = true ;
        mp[P(S,T)] = true ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}