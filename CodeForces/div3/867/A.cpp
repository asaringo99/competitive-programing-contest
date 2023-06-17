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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define ptv(V) for(auto u : V) { cout << u << " "; } cout << endl;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

vector<int> R;

void dfs(vector<ld> A){
    int n = A.size();
    if(n == 1 && A[0] == 0.5) {
        for(int u : R) cout << u << " "; cout << endl;
        cout << A[0] << endl;
    }
    rep(i,n-1){
        vector<ld> B;
        R.push_back(i);
        rep(j,n){
            if(j == i + 1) continue;
            if(j == i) B.push_back((A[j] + A[j+1])/2);
            else B.push_back(A[j]);
        }
        dfs(B);
        R.pop_back();
    }
}

void solve(){
    vector<ld> A = {0,1,0,1,0,1,0,1,0};
    dfs(A);
}

int main(){
    fast_io
    solve();
}