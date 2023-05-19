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
ll dp[303][303] ;

inline ll rec(int x , int y){
    if(y - x == 1) return dp[x][y] = 0 ;
    if(y - x == 2) return dp[x][y] = 0 ;
    if(y - x == 3){
        if(S[x] == 'i' && S[x+1] == 'w' && S[x+2] == 'i') return dp[x][y] = 1 ;
        return dp[x][y] = 0 ;
    }
    if(dp[x][y] != -1) return dp[x][y] ;
    ll res = 0 ;
    if(S[x] == 'i' && S[x+1] == 'w' && S[y-1] == 'i'){
        if((y - x) % 3 == 0 && rec(x+2,y-1) == (y - x - 3) / 3) chmax(res,rec(x+2,y-1) + 1) ;
    }
    if(S[x] == 'i' && S[y-2] == 'w' && S[y-1] == 'i'){
        if((y - x) % 3 == 0 && rec(x+1,y-2) == (y - x - 3) / 3) chmax(res,rec(x+1,y-2) + 1) ;
    }
    for(int i = x + 1 ; i < y ; i++){
        chmax(res,rec(x,i)+rec(i,y)) ;
    }
    return dp[x][y] = res ;
}

int main(){
    cin >> S ;
    n = S.size() ;
    rep(i,n+1) rep(j,n+1) dp[i][j] = -1 ;
    cout << rec(0,n) << endl ;
}