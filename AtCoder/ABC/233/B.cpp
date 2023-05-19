#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int l , r;
string S ;

int main(){
    cin >> l >> r >> S ;
    string T = "" ;
    rep(i,l-1) cout << S[i] ;
    rrep(i,l-1,r) T += S[i] ; 
    reverse(T.begin(),T.end()) ;
    cout << T ;
    rrep(i,r,S.size()) cout << S[i] ;
    cout << endl ;
}