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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

vector<int> A;
vector<int> dp;
unordered_set<int> st;

int rec(int S){
    if(dp[S] != 0) return dp[S];
    if(st.count(S)) return dp[S] = S;
    rep(i,25){
        if(!(S >> i & 1)) continue;
        int val = rec(S ^ (1 << i));
        if(val != -1) return dp[S] = val;
    }
    return dp[S] = -1;
}

void solve(){
    int n;
    cin >> n;
    A = vector<int>(n);
    rep(i,n) cin >> A[i], st.insert(A[i]);
    dp = vector<int>(1<<22,0);
    rep(i,n){
        int val = (((1 << 22) - 1) ^ A[i]);
        cout << rec(val) << " ";
    }
    cout << endl;
}

int main(){
    fast_io
    solve();
}