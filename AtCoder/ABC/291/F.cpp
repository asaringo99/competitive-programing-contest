#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define all(a) a.begin(), a.end()
#define endl "\n"

int n, m;
char C[101010][20];
// 0: もうどこを通っても良い
ll dp[101010];
ll ep[101010];

ll rec(int v){
    // cout << v << endl;
    if(v == n - 1) return dp[v] = 0;
    if(dp[v] != -1) return dp[v];
    ll res = 1e9;
    rep(i,m){
        if(v+i+1>=n) continue;
        if(C[v][i] == '1') chmin(res,rec(v+i+1)+1);
    }
    return dp[v] = res;
}

ll qec(int v){
    if(v == 0) return ep[v] = 0;
    if(ep[v] != -1) return ep[v];
    ll res = 1e9;
    rep(i,m){
        if(v-i-1 < 0) continue;
        if(C[v-i-1][i] == '1') chmin(res,qec(v-i-1)+1);
    }
    return ep[v] = res;
}

int main(){
    // fast_io
    cin >> n >> m;
    rep(i,n){
        string S;
        cin >> S;
        rep(j,m) C[i][j] = S[j];
    }
    rep(i,n+1) dp[i] = -1;
    rep(i,n+1) ep[i] = -1;
    rep(i,n) rec(i);
    rep(i,n) qec(i);
    // rep(i,n) cout << rec(i) << " "; cout << endl;
    // rep(i,n) cout << qec(i) << " "; cout << endl;
    rrep(i,1,n-1){
        ll res = 1e9;
        for(int j = i - 1; j >= i - m; j--){
            for(int k = i + 1; k <= j + m; k++){
                if(k - j > m) continue;
                // cout << j << " " << k << endl;
                if(C[j][k-j-1] == '1') {
                    
                    chmin(res,rec(k)+qec(j)+1);
                }
            }
        }
        if(res == 1e9) res = -1;
        cout << res << " ";
    }
    cout << endl;
}