#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

set<string> st ;

int main(){
    st.insert("ABC") ;
    st.insert("AGC") ;
    st.insert("ARC") ;
    st.insert("AHC") ;
    rep(i,3){
        string S ;
        cin >> S ;
        st.erase(S) ;
    }
    cout << (*st.begin()) << endl ;
}