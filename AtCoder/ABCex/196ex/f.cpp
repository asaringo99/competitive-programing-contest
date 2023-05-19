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

string S , T ;
int X[1010101] , Y[1010101] ;
P next_[1010101][2] ;
int dp[1010101][2] ;

int main(){
    cin >> S >> T ;
    int n = S.size() , m = T.size() ;
    X[n] = n ; Y[n] = n ;
    for(int i = n - 1 ; i >= 0 ; i--){
        X[i] = X[i+1] ;
        Y[i] = Y[i+1] ;
        if(S[i] == '0') X[i] = i ;
        if(S[i] == '1') Y[i] = i ;
    }
    
}