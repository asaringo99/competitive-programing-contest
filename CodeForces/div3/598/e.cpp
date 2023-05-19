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

int z ;
int A[202020];
P X[202020];
ll dp[202020][3];
tuple<int,int> pre[202020][3];
int res[202020];

void solve(){
    int n;
    cin >> n;
    rep(i,n) {
        cin >> A[i];
        X[i] = {A[i],i};
    }
    sort(A,A+n);
    sort(X,X+n);
    rep(i,n+1) rep(j,3) dp[i][j] = 1e18;
    dp[0][0] = -A[0];
    pre[0][0] = {-1,-1};
    rrep(i,1,n){
        if(dp[i][0] > dp[i-1][2] - A[i]){
            dp[i][0] = dp[i-1][2] - A[i];
            pre[i][0] = {i-1,2};
        }
        if(dp[i][1] > dp[i-1][0]){
            dp[i][1] = dp[i-1][0];
            pre[i][1] = {i-1,0};
        }
        if(dp[i][1] > dp[i-1][1]){
            dp[i][1] = dp[i-1][1];
            pre[i][1] = {i-1,1};
        }
        if(dp[i][2] > dp[i-1][1] + A[i]){
            dp[i][2] = dp[i-1][1] + A[i];
            pre[i][2] = {i-1,1};
        }
    }
    int m = n - 1, k = 2, cnt = 0;
    while(m != -1 && k != -1){
        auto[x,t] = pre[m][k];
        if(k == 2) cnt++;
        res[X[m].second] = cnt;
        m = x;
        k = t;
    }
    cout << dp[n-1][2] << " " << cnt << endl;
    rep(i,n) cout << res[i] << " "; cout << endl;
}

int main(){
    fast_input_output
    solve();
}