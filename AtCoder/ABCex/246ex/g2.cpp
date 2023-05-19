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

int n ;
vector<int> G[202020];
int A[202020], B[202020], C[202020];
int dp[202020];

void dfs(int v, int prev){
    int res = 0;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v);
        res += dp[u];
    }
    res--;
    if(res < 0) res = 0;
    res += B[v];
    dp[v] = res;
}

bool f(int x){
    rep(i,n){
        if(A[i] >= x) B[i] = 1;
        else B[i] = 0;
    }
    dfs(0,-1);
    return dp[0] > 0;
}

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,1,n) cin >> A[i], C[i] = A[i];
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    int lef = 0, rig = n;
    sort(C,C+n);
    while(rig - lef > 1){
        int mid = (lef + rig) / 2;
        if(f(C[mid])) lef = mid;
        else rig = mid;
    }
    cout << C[lef] << endl;
}