#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

const int mod = 10000000 ;

int f(int dir, char c){
    if(dir == 0 && c == 'L') return 1 ;
    if(dir == 0 && c == 'R') return 3 ;
    if(dir == 1 && c == 'L') return 2 ;
    if(dir == 1 && c == 'R') return 0 ;
    if(dir == 2 && c == 'L') return 3 ;
    if(dir == 2 && c == 'R') return 1 ;
    if(dir == 3 && c == 'L') return 0 ;
    if(dir == 3 && c == 'R') return 2 ;
    return -1 ;
}

int D[2],n;
string S;

int dp[2][10101][1010] ;

int main(){
    cin >> D[0] >> D[1] >> n >> S;
    int dir = S[0] == 'L' ? 0 : 1 ;
    dp[0][0][0] = 1 ;
    dp[1][0][0] = 1 ;
    int W = D[0], H = D[1];
    int a = 0 , b = 0 ;
    rep(i,n+1){
        if(dir==0) {
            rep(j,D[0]) dp[0][a+1][j+1]=(dp[0][a+1][j]+dp[0][a][j])%mod;
            a++;
        }
        if(dir==1) {
            rep(j,D[1]) dp[1][b+1][j+1]=(dp[1][b+1][j]+dp[1][b][j])%mod;
            b++;
        }
        if(dir==2) {
            rep(j,D[0]) dp[0][a+1][W-1-j]=(dp[0][a+1][W-j]+dp[0][a][W-j])%mod;
            a++;
        }
        if(dir==3) {
            rep(j,D[1]) dp[1][b+1][H-1-j]=(dp[1][b+1][H-j]+dp[1][b][H-j])%mod;
            b++ ;
        }
        if(i==n) break;
        dir=f(dir,S[i]);
    }
    ll res = (ll)dp[0][a][W] * (ll)dp[1][b][H] % mod;
    cout << res << endl ;
}