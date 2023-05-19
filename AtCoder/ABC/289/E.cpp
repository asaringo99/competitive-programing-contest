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
vector<vector<int>> G;
vector<int> C;
vector<int> ad, td;

int bfs(){
    vector<vector<int>> mp(n,vector<int>(n,1e8));
    mp[0][n-1] = 0;
    queue<pair<int,int>> que;
    que.push({0,n-1});
    while(!que.empty()){
        auto[v,u] = que.front(); que.pop();
        bool aw = false, ab = false;
        bool tw = false, tb = false;
        for(int nv : G[v]){
            if(C[nv]) tb = true;
            else tw = true;
        }
        for(int nu : G[u]){
            if(C[nu]) ab = true;
            else aw = true;
        }
        if(!(aw && tb)){
            aw = false;
            tb = false;
        }
        if(!(tw && ab)){
            tw = false;
            ab = false;
        }
        for(int nv : G[v]) for(int nu : G[u]) {
            if(C[nv] && tb && !C[nu] && aw){
                if(mp[nv][nu] > mp[v][u] + 1){
                    mp[nv][nu] = mp[v][u] + 1;
                    que.push({nv,nu});
                }
            }
            if(!C[nv] && tw && C[nu] && ab){
                if(mp[nv][nu] > mp[v][u] + 1){
                    mp[nv][nu] = mp[v][u] + 1;
                    que.push({nv,nu});
                }
            }
        }
    }
    if(mp[n-1][0] == 1e8) return -1;
    else return mp[n-1][0];
}

void solve(){
    cin >> n >> m;
    C = vector<int>(n);
    rep(i,n) cin >> C[i];
    G = vector<vector<int>>(n);
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    ad = vector<int>(n,1e8);
    td = vector<int>(n,1e8);
    td[0] = 0;
    ad[n-1] = 0;
    cout << bfs() << endl;
}

int main(){
    // fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}