#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;

int main(){
    cin >> S ;
    set<char> st ;
    rep(i,4) st.insert(S[i]) ;
    if(st.size() == 1){
        cout << "Weak" << endl ;
        return 0 ;
    }
    bool ok = true ;
    rep(i,3){
        if((S[i+1] - '0') != ((S[i] - '0') + 1) % 10) ok = false ;
    }
    if(ok) cout << "Weak" << endl ; 
    else cout << "Strong" << endl ;
}