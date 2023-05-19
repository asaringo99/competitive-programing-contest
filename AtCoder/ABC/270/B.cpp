#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

int x, y, z;

int dp[4040][2];

void bfs(){
    rep(i,4040) rep(j,2) dp[i][j] = 1e9;
    x += 2000;
    y += 2000;
    z += 2000;
    queue<tuple<int,int,int>> que;
    que.push({2000,0,0});
    dp[2000][0] = 0;
    while(!que.empty()){
        auto[pos,c,d] = que.front(); que.pop();
        if(pos-1 != y && dp[pos-1][c] > dp[pos][c] + 1){
            dp[pos-1][c] = dp[pos][c] + 1;
            que.push({pos-1,c,dp[pos-1][c]});
        }
        if(pos+1 != y && dp[pos+1][c] > dp[pos][c] + 1){
            dp[pos+1][c] = dp[pos][c] + 1;
            que.push({pos+1,c,dp[pos+1][c]});
        }
        if(pos-1 == z && dp[pos-1][1] > dp[pos][c] + 1){
            dp[pos-1][1] = dp[pos][c] + 1;
            que.push({pos-1,1,dp[pos-1][1]});
        }
        if(pos+1 == z && dp[pos+1][1] > dp[pos][c] + 1){
            dp[pos+1][1] = dp[pos][c] + 1;
            que.push({pos+1,1,dp[pos+1][1]});
        }
        if(pos-1 == y && c == 1 && dp[pos-1][1] > dp[pos][c] + 1){
            dp[pos-1][1] = dp[pos][c] + 1;
            que.push({pos-1,1,dp[pos-1][1]});
        }
        if(pos+1 == y && c == 1 && dp[pos+1][1] > dp[pos][c] + 1){
            dp[pos+1][1] = dp[pos][c] + 1;
            que.push({pos+1,1,dp[pos+1][1]});
        }
    }
}

int main(){
    fast_input_output
    cin >> x >> y >> z ;
    bfs();
    int res = min(dp[x][0], dp[x][1]);
    if(res == 1e9) res = -1;
    cout << res << endl;
}