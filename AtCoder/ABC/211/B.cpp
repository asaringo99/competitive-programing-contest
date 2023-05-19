#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

set<string> st ;
string S[4] ;

int main(){
    rep(i,4) cin >> S[i] ;
    st.insert("H") ;
    st.insert("2B") ;
    st.insert("3B") ;
    st.insert("HR") ;
    rep(i,4){
        if(st.count(S[i]) == 0){
            cout << "No" << endl ;
            return 0 ;
        }
        st.erase(S[i]) ;
    }
    cout << "Yes" << endl ;
}