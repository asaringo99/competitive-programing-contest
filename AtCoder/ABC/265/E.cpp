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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

const int mod = 998244353 ;

int n, m ;
ll dx[3], dy[3];
ll X[101010], Y[101010];
set<pair<int,int>> st;
ll dp[303][303][303];

int main(){
    fast_input_output
    cin >> n >> m;
    rep(i,3) cin >> dx[i] >> dy[i];
    rep(i,m) {
        cin >> X[i] >> Y[i];
        st.insert(P(X[i],Y[i]));
    }
    dp[0][0][0] = 1;
    rep(i,n){
        rep(j,i+1){
            rep(k,i-j+1){
                ll x = j * dx[0] + k * dx[1] + (i-j-k) * dx[2];
                ll y = j * dy[0] + k * dy[1] + (i-j-k) * dy[2];
                if(!st.count(P(x+dx[0],y+dy[0]))) (dp[i+1][j+1][k] += dp[i][j][k]) %= mod;
                if(!st.count(P(x+dx[1],y+dy[1]))) (dp[i+1][j][k+1] += dp[i][j][k]) %= mod;
                if(!st.count(P(x+dx[2],y+dy[2]))) (dp[i+1][j][k] += dp[i][j][k]) %= mod;
            }
        }
    }
    ll res = 0;
    rep(i,n+1) rep(j,n-i+1) (res += dp[n][i][j]) %= mod;
    cout << res << endl;
}