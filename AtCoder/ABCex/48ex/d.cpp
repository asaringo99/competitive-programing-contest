#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string s ;

int main(){
    cin >> s ;
    int n = s.size() ;
    if(s[0] == s[s.size()-1]){
        if(n % 2 == 0) cout << "First" << endl ;
        if(n % 2 == 1) cout << "Second" << endl ;
    }
    if(s[0] != s[s.size()-1]){
        if(n % 2 == 0) cout << "Second" << endl ;
        if(n % 2 == 1) cout << "First" << endl ;
    }
}