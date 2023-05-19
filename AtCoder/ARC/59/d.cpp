#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
string S ;

int main(){
    cin >> S ;
    n = S.size() ;
    rep(i,n-1){
        if(S[i] == S[i+1]){
            cout << i+1 << " " << i+2 << endl ;
            return 0 ;
        }
    }
    rep(i,n-2){
        if(S[i] == S[i+2]){
            cout << i+1 << " " << i+3 << endl ;
            return 0 ;
        }
    }
    cout << -1 << " " << -1 << endl ;
}