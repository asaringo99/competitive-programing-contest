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
#define a_z "abcdefghijklmnopqrstuvwxyz"

string S , T ;
map<char,int> mp ;

int main(){
    cin >> S >> T ;
    rep(i,26) mp[a_z[i]] = i ;
    bool res = false ;
    rep(i,26){
        bool ok = true ;
        rep(j,S.size()){
            if(a_z[(mp[S[j]] + i) % 26] != T[j]) ok = false ;
        }
        if(ok){
            cout << "Yes" << endl ;
            return 0 ;
        }
    }
    cout << "No" << endl ;
}