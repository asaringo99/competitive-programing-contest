#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

string S ;

int main(){
    cin >> S ;
    string T = "" ;
    int n = S.size() ;
    string fr , bc ;
    bool flag = true ;
    for(int i = 0 ; i < n ; i++){
        if(S[i] == 'R'){
            if(flag) flag = false ;
            else flag = true ;
        }
        else{
            if(flag){
                bc += S[i] ;
            }
            else{
                fr += S[i] ;
            }
        }
    }
    if(flag){
        reverse(fr.begin(),fr.end()) ;
        T = fr + bc ;
    }
    else{
        reverse(bc.begin(),bc.end()) ;
        T = bc + fr ;
    }
    string res = T ;
    int i = 0 ;
    vector<char> ans ;
    ans.push_back('1') ;
    set<int> S ;
    for(int i = 0 ; i < res.size() ; i++){
        if(ans[ans.size() - 1] != res[i]) ans.push_back(res[i]) ;
        else ans.pop_back() ;
    }
    for(int i = 1 ; i < ans.size() ; i++) cout << ans[i] ;
    cout << endl ;
}