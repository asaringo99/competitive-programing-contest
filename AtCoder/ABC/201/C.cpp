#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

string S ;

int main(){
    cin >> S ;
    set<int> used ;
    set<int> ques ;
    for(int i = 0 ; i < 10 ; i++){
        if(S[i] == 'o') {
            used.insert(i) ;
            ques.insert(i) ;
        }
        if(S[i] == '?') ques.insert(i) ;
    }
    int res = 0 ;
    for(int i = 0 ; i < 10000 ; i++){
        set<int> check = used ;
        string T = "" ;
        string K = to_string(i) ;
        for(int j = 0 ; j < 4 - K.size() ; j++) T += '0' ;
        T += K ;
        int count = 0 ;
        bool ok = true ;
        for(char u : T){
            if(ques.count(u - '0') == 0) ok = false ;
            check.erase(u - '0') ;
        }
        if(check.empty() && ok) res++ ;
    }
    cout << res << endl ;
}