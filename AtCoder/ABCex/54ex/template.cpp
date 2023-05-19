#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S , T , U ;

int main(){
    cin >> S >> T >> U ;
    if(S[S.size()-1] == T[0] && T[T.size() - 1] == U[0]) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}