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

int mod , r ;
int dp[41][101010][10] ;

int main(){
    cin >> mod >> r ;
    string s = to_string(r) ;
    int t = 0 ;
    int sum = 0 ;
    rep(i,s.size()){
        int u = s[i] - '0' ;
        if(u == 0 && t == 0) sum += 1 ;
        else if(t == 0) sum += (u-1)/3+(u-1)%3+2 ;
        else if(u == 0) sum += (t-1)/3+(t-1)%3+2 ;
        else sum += abs((t-1)/3-(u-1)/3) + abs((t-1)%3-(u-1)%3)+1;
        t = u ;
    }
    rep(i,sum+1) rep(j,mod) rep(k,10) dp[i][j][k] = 1e9 ;
    dp[0][0][0] = 0 ;
    rep(i,sum+1){
        rep(j,mod){
            rep(k,10){
                if(dp[i][j][k] == 1e9) continue;
                rep(x,10){
                    if(x == 0 && k == 0){
                        if(dp[i][j][k]+1 > sum) continue;
                        chmin(dp[i+1][(j*10)%mod][0],dp[i][j][k]+1) ;
                    }
                    else if(x == 0){
                        if(dp[i][j][k]+abs(k-1)/3+abs(k-1)%3+1 > sum) continue;
                        chmin(dp[i+1][(j*10)%mod][0],dp[i][j][k]+abs(k-1)/3+abs(k-1)%3+2) ;
                    }
                    else if(k == 0){
                        if(dp[i][j][k]+abs(x-1)/3+abs(x-1)%3+1 > sum) continue;
                        chmin(dp[i+1][(j*10+x)%mod][x],dp[i][j][k]+abs(x-1)/3+abs(x-1)%3+2) ;
                    }
                    else{
                        int dx = abs((x - 1) / 3 - (k - 1) / 3) ;
                        int dy = abs((x - 1) % 3 - (k - 1) % 3) ;
                        if(dp[i][j][k]+dx+dy > sum) continue;
                        chmin(dp[i+1][(j*10+x)%mod][x],dp[i][j][k]+dx+dy+1) ;
                    }
                }
            }
        }
    }
    int res = sum ;
    rep(i,sum+1) rep(j,10) chmin(res,dp[i][r][j]) ;
    cout << res << endl ;
}