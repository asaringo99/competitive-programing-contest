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
typedef pair<int,char> P ;
typedef tuple<int,int,int,int> TP ;
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

int z ;

void solve(){
    int n, r, b;
    string S;
    cin >> n >> r >> b >> S;
    vector<int> digit(n);
    rep(i,n) digit[i] = S[i] - '0';
    vector<vector<vector<vector<bool>>>> dp(n+1,vector<vector<vector<bool>>>(n+1,vector<vector<bool>>(r,vector<bool>(b,false))));
    vector<vector<vector<vector<TP>>>> ep(n+1,vector<vector<vector<TP>>>(n+1,vector<vector<TP>>(r,vector<TP>(b,{-1,-1,-1,-1}))));
    dp[0][0][0][0] = true;
    rep(i,n){
        int v = digit[i];
        rep(j,i+1) {
            rep(x,r) rep(y,b){
                if(!dp[i][j][x][y]) continue;
                {
                    int val = x * 10 + v;
                    val %= r;
                    dp[i+1][j+1][val][y] = true;
                    ep[i+1][j+1][val][y] = {i,j,x,y};
                }
                {
                    int val = y * 10 + v;
                    val %= b;
                    dp[i+1][j][x][val] = true;
                    ep[i+1][j][x][val] = {i,j,x,y};
                }
            }
        }
    }
    int res = -1, c = -1;
    for(int i = n - 1 ; i > 0 ; i--){
        if(dp[n][i][0][0]) {
            if(res == -1){
                res = abs(n - i * 2);
                c = i;
            }
            else{
                if(res > abs(n - i * 2)){
                    res = abs(n - i * 2);
                    c = i;
                }
            }
        }
    }
    if(res == -1){
        cout << -1 << endl;
        return;
    }
    vector<char> ans;
    int i = n, j = c, k = 0, l = 0;
    while(i != 0){
        auto[a,b,x,y] = ep[i][j][k][l];
        if(j != b) ans.push_back('R');
        else ans.push_back('B');
        i = a, j = b, k = x, l = y;
    }
    reverse(ans.begin(),ans.end());
    for(char u : ans) cout << u; cout << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}