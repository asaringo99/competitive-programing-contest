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

string X ;
ll S[505050] ;
vector<ll> Y ;

int main(){
    cin >> X ;
    int n = X.size() ;
    reverse(X.begin(),X.end()) ;
    rep(i,n) S[i+1] = S[i] + (X[i] - '0') ;
    ll s = 0 ;
    rep(i,n){
        Y.push_back((s+S[n]-S[i])%10) ;
        s = (s+S[n]-S[i])/10 ;
    }
    while(s > 0){
        Y.push_back(s%10) ;
        s = s/10 ;
    }
    reverse(Y.begin(),Y.end()) ;
    rep(i,Y.size()) cout << Y[i] ;
    cout << endl ;
}