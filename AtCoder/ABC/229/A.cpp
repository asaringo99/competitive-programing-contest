#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S , T ;

int main(){
    cin >> S >> T ;
    if(S == "#." && T == ".#") cout << "No" << endl ;
    else if(T == "#." && S == ".#") cout << "No" << endl ;
    else cout << "Yes" << endl ;
}