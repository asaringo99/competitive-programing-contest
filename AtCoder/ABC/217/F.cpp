#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
const int mod = 998244353 ;
map<P,ll> mp ;
ll dp[400][400] ;
ll C[400][400] ;

void f(){
    C[0][0] = 1 ;
    rep(i,400) rep(j,400){
        (C[i+1][j] += C[i][j]) %= mod ;
        (C[i+1][j+1] += C[i][j]) %= mod ;
    }
}

ll rec(ll a , ll b){
    if(a > b) return 1 ;
    if(dp[a][b] >= 0) return dp[a][b] ;
    ll res = 0 ;
    if(mp[P(a,b)]) (res += rec(a+1,b-1)) %= mod ;
    int r = 0 ;
    for(int i = a + 1 ; i < b ; i += 2){
        r++ ;
        if(!mp[P(a,i)]) continue ;
        res += rec(a+1,i-1) * rec(i+1,b) % mod * C[(b-a+1)/2][r] % mod ;
        res %= mod ;
    }
    return dp[a][b] = res ;
}

int main(){
    f() ;
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        mp[P(a,b)] = true ;
        mp[P(b,a)] = true ;
    }
    rep(i,400) rep(j,400) dp[i][j] = -1 ;
    cout << rec(0,2*n-1) << "\n" ;
}