#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
string S ;

int main(){
    cin >> S ;
    n = S.size() ;
    ll res = 0;
    rep(i,n){
        if(S[i] == '.'){
            int u = S[i+1]-'0';
            if(u >= 5) res++ ;
            cout << res << endl;
        }
        res *= 10;
        res += S[i] - '0';
    }
}