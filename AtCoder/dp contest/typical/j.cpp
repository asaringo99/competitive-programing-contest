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
ld dp[1<<20] ;

ld rec(int S){
    if(bit_count(S) == 16) return dp[S] = 0 ;
    if(dp[S] >= 0) return dp[S] ;
    ld res = 1e10 ;
    for(int i = 1 ; i < 15 ; i++){
        if(S >> i & 1 && S >> (i - 1) & 1 && S >> (i + 1) & 1) continue ;
        else if(S >> (i+1) & 1 && S >> (i-1) & 1) chmin(res,rec(S|1<<i)+3.0) ;
        else if(S >> i & 1 && S >> (i-1) & 1) chmin(res,rec(S|1<<(i+1))+3.0) ;
        else if(S >> i & 1 && S >> (i+1) & 1) chmin(res,rec(S|1<<(i-1))+3.0) ;
        else if(S >> i & 1) chmin(res,(rec(S|1<<(i-1))+rec(S|1<<(i+1)))/2+1.5) ;
        else if(S >> (i-1) & 1) chmin(res,(rec(S|1<<i)+rec(S|1<<(i+1)))/2+1.5) ;
        else if(S >> (i+1) & 1) chmin(res,(rec(S|1<<i)+rec(S|1<<(i-1)))/2+1.5) ;
        else chmin(res,(rec(S|1<<i)+rec(S|1<<(i-1))+rec(S|1<<(i+1)))/3+1.0) ;
    }
    return dp[S] = res ;
}

int main(){
    cin >> n ;
    int S = (1 << 16) - 1 ;
    rep(i,n){
        int x ;
        cin >> x ;
        S ^= 1 << x ;
    }
    rep(T,1<<16) dp[T] = -1 ;
    cout << fixed << setprecision(25) << rec(S) << endl ;
}