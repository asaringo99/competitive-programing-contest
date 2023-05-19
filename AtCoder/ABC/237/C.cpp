#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
string S , T ;

int main(){
    cin >> S ;
    T = S ;
    reverse(T.begin(),T.end()) ;
    int id = 0 ;
    rep(i,T.size()) {
        if(T[i] == 'a') id = i + 1 ;
        else break ;
    }
    int kd = 0 ;
    rep(i,S.size()) {
        if(S[i] == 'a') kd = i + 1 ;
        else break ;
    }
    id -= kd ;
    if(id < 0){
        cout << "No" << endl ;
        return 0 ;
    }
    string U = "" ;
    rep(i,id) U += 'a' ;
    rep(i,S.size()) U += S[i] ;
    bool ok = true ;
    rep(i,U.size()) if(U[i] != U[U.size()-i-1]) ok = false ;
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}