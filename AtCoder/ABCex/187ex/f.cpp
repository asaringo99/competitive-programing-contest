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

int n , m ;
bool A[20][20] ;
bool use[1 << 20] ;
int dp[1 << 20] ;

inline int rec(int S){
    if(use[S]) return dp[S] = 1 ;
    if(dp[S] != -1) return dp[S] ;
    int res = 100 ;
    for(int T = S ; T > 0 ; T = (T - 1) & S){
        if(T == S || T == 0) continue ;
        chmin(res,rec(T)+rec(T^S)) ;
    }
    return dp[S] = res ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        A[a][b] = true ;
        A[b][a] = true ;
    }
    rrep(S,1,1<<n){
        bool ok = true ;
        rep(i,n) rep(j,n){
            if(S >> i & 1 && S >> j & 1 && i != j && !A[i][j]) ok = false ;
        }
        if(ok) use[S] = true ;
    }
    rep(i,1<<n) dp[i] = -1 ;
    cout << rec((1<<n)-1) << endl ;
}