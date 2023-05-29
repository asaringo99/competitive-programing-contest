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

vector<set<pair<int,int>>> G;

void solve(){
    int n;
    cin >> n;
    G = vector<set<pair<int,int>>>(n);
    queue<tuple<int,int,int>> que;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].insert({v,i}) ;
        G[v].insert({u,i}) ;
        if(u == 0){
            que.push({v,u,i});
        }
        if(v == 0){
            que.push({u,v,i});
        }
    }
    int res = 0;
    while(!que.empty()){
        queue<tuple<int,int,int>> Q;
        while(!que.empty()){
            auto[v,prevv,id] = que.front(); que.pop();
            // cout << res << " " << v << " " << prevv << endl;
            for(auto [u,j] : G[v]){
                if(u == prevv) continue;
                // cout << v << " " << u << " " << j << " " << id << endl;
                if(id > j) Q.push({u,v,j});
                else que.push({u,v,j});
            }
        }
        res++;
        // cout << res << endl;
        swap(que,Q);
    }
    cout << res << endl;
}

int main(){
    // fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}