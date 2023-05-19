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

ll d[101010];
vector<int> G[101010];
int start, depth;

void dfs(int v, int prev, int dep){
    d[v] = dep;
    if(dep > depth){
        start = v;
        depth = dep;
    }
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v,dep+1);
    }
}

vector<int> A[101010];
vector<int> B[101010];
int node, dist;

void rec(int v, int prev, int dep){
    A[dep].push_back(v);
    if(dist < dep){
        dist = dep;
        node = v;
    }
    for(int u : G[v]){
        if(u == prev) continue;
        rec(u,v,dep+1);
    }
}

void sec(int v, int prev, int dep){
    B[dep].push_back(v);
    for(int u : G[v]){
        if(u == prev) continue;
        sec(u,v,dep+1);
    }
}

void solve(){
    int n;
    cin >> n;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfs(0,-1,0);
    rec(start,-1,0);
    sec(node,-1,0);
    // rep(i,n){
    //     cout << i << " : ";
    //     for(int u : A[i]) cout << u << " "; cout << endl;
    // }
    // cout << endl;
    // rep(i,n){
    //     cout << i << " : ";
    //     for(int u : B[i]) cout << u << " "; cout << endl;
    // }
    set<int> st;
    bool ok = false;
    vector<int> ans;
    for(int i = n; i >= 1; i--){
        if(!A[i].empty() || !B[i].empty()){
            ok = true;
        }
        for(int u : A[i]) st.insert(u);
        for(int u : B[i]) st.insert(u);
        ans.push_back(n-st.size()+ok);
    }
    reverse(all(ans));
    for(int u : ans) cout << u << " "; cout << endl;
}

int main(){
    fast_io
    solve();
}