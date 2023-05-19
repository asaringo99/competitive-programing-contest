#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S ;

int main(){
    string s1 = "oxxoxxoxxoxxoxxoxxoxxoxxoxx" ;
    cin >> S ;
    bool ok = false ;
    rep(i,3) {
        bool gd = true ;
        rep(j,S.size()){
            if(s1[i+j] != S[j]) gd = false ;
        }
        if(gd) ok = true ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}