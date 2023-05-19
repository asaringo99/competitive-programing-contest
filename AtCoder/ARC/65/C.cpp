#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "YES" << endl 
#define NO cout << "NO" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

string S ;

string state[4] = {"dream" , "dreamer" , "erase" , "eraser"} ;

int main(){
    cin >> S ;
    int n = S.size() ;
    reverse(S.begin(),S.end()) ;
    int t = -1 ;
    bool ok = true ;
    while(t < n){
        if(t == n - 1) break ;
        string match = "" ;
        int k = t + 1 ;
        for(int i = k ; i < min(n,k + 5) ; i++){
            match += S[i] ;
            t = i ;
        }
        if(t < n && (match == "maerd" || match == "esare")) continue ;
        t++ ;
        match += S[t] ;
        if(t < n && (match == "resare")) continue ;
        t++ ;
        match += S[t] ;
        if(t < n && (match == "remaerd")) continue ;
        t++ ;
        ok = false ;
    }
    if(ok) YES ;
    else NO ;
}