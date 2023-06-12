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

void solve(){
    string S;
    cin >> S;
    int n = S.size();
    vector<int> A(n+1,0);
    vector<int> B(n+1,0);
    for(int i = 0; i < n; i++){
        A[i+1] = A[i];
        if('a' <= S[i] && S[i] <= 'z') A[i+1]++;
    }
    for(int i = 0; i < n; i++){
        B[i+1] = B[i];
        if('A' <= S[n-1-i] && S[n-1-i] <= 'Z') B[i+1]++;
    }
    int res = 1e9;
    rep(i,n+1){
        chmin(res,A[i] + B[n-i]);
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}