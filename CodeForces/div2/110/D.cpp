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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> A(n);
    vector<vector<int>> T(n,vector<int>());
    vector<vector<int>> F(n,vector<int>());
    int f = 0;
    rep(i,n){
        string s;
        cin >> s;
        if(s[0] == '+') A[i].first = 1;
        else A[i].first = 0, f++;
        int v = 0;
        rrep(j,1,s.size()){
            v *= 10;
            v += s[j] - '0';
        }
        v--;
        if(s[0] == '+') T[v].push_back(i);
        else F[v].push_back(i);
        A[i].second = v;
    }
    vector<int> ans(n,2);
    int ok = 0;
    vector<int> V;
    rep(i,n){
        if(T[i].size() + f - F[i].size() == m){
            V.push_back(i);
        }
        else{
            for(int u : T[i]) ans[u] = 0;
        }
    }
    if(V.size() == 1){
        rep(i,n) if(ans[i] == 2) ans[i] = 1;
        for(int u : V){
            for(int u : T[u]) ans[u] = 1;
            for(int u : F[u]) ans[u] = 0;
        }
    }
    rep(i,n){
        if(ans[i] == 0) cout << "Lie" << endl;
        if(ans[i] == 1) cout << "Truth" << endl;
        if(ans[i] == 2) cout << "Not defined" << endl;
    }
}

int main(){
    fast_io
    solve();
}