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
string S ;

int main(){
    cin >> n >> S ;
    string T = "" ;
    rep(i,n){
        if(S[i] == 'A') T += "BB" ;
        else T += S[i] ;
    }
    int m = T.size() ;
    string U = "" ;
    int i = 0 ;
    while(i < m){
        if(i + 1 < m && T[i] == 'B' && T[i+1] == 'B') {
            U += 'A' ;
            i += 2 ;
        }
        else{
            U += T[i] ;
            i++ ;
        }
    }
    cout << U << endl ;
}