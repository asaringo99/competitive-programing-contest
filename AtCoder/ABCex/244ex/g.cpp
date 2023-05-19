#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"

int n , m ;
vector<int> G[202020] ;
string S;
bool C[202020] ;
int cnt[202020] ;
bool used[202020];
vector<int> res;

void go(int v, int prev){
    cnt[v]++;
    cnt[prev]++;
    res.push_back(v);
    res.push_back(prev);
}

void dfs(int v, int prev){
    used[v] = true;
    cnt[v]++;
    res.push_back(v);
    for(int u : G[v]){
        if(u == prev) continue;
        if(used[u]) continue;
        used[u] = true;
        dfs(u,v);
        if(cnt[u] % 2 != C[u]) go(u,v);
    }
    if(v != 0) {
        cnt[prev]++;
        res.push_back(prev);
    }
}

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    cin >> S ;
    rep(i,n) C[i] = (S[i] == '1' ? true : false);
    dfs(0,-1);
    if(C[0] != cnt[0] % 2) res.pop_back();
    cout << res.size() << endl;
    for(int u : res) cout << u + 1 << " "; cout << endl;
}