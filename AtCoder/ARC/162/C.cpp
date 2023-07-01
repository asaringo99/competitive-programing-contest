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
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

vector<vector<int>> G;
vector<int> A;

void getv(int v, int prev, vector<int> &X){
    X.push_back(v);
    for(int u : G[v]){
        if(u == prev) continue;
        getv(u,v,X);
    }
}

void dfs(int v, int prev, bool &ok, int &n, int &k){
    vector<int> X;
    getv(v,prev,X);
    set<int> st, canget;
    rep(x,n+10) st.insert(x);
    int emptynode = 0;
    // for(int u : X) cout << u << " "; cout << endl;
    for(int x : X) {
        if(A[x] != -1) st.erase(A[x]);
        else emptynode++;
    }
    int cnt = emptynode / 2;
    if(emptynode % 2 == 1) cnt++;
    chmin(cnt,1);
    while(cnt > 0) {
        auto it = st.begin();
        canget.insert(*it);
        st.erase(it);
        cnt--;
    }
    auto it = st.begin();
    canget.insert(*it);
    if(canget.count(k) && emptynode <=1) ok = true;
    // cout << "o :";
    // for(int u : canget) cout << u << " "; cout << endl;

    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v,ok,n,k);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    G = vector<vector<int>>(n);
    vector<int> P(n);
    A = vector<int>(n);
    rrep(i,1,n){
        int p;
        cin >> p;
        p--;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    int enode = 0;
    rep(i,n) cin >> A[i];
    rep(i,n) if(A[i] == -1) enode++;
    bool ok = false;
    dfs(0,-1,ok,n,k);
    if(ok) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}