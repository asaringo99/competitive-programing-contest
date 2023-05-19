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
#define endl "\n"

pair<int,int> bfs(vector<P> &vec, int &H, int &W){
    vector<vector<ll>> D(H,vector<ll>(W,0));
    for(auto p: vec){
        auto[x,y] = p;
        rep(i,H) rep(j,W) chmax(D[i][j],abs(i-x)+abs(j-y));
    }
    ll res = 1e18;
    int ax = -1, ay = -1;
    rep(i,H) rep(j,W) {
        if(res > D[i][j]){
            res = D[i][j];
            ax = i + 1;
            ay = j + 1;
        }
    }
    return {ax, ay};
}

void solve(){
    int H, W;
    cin >> H >> W;
    int n = 0;
    vector<P> cor;
    vector<TP> S, T;
    vector<vector<char>> C(H,vector<char>(W));
    rep(i,H) rep(j,W) {
        cin >> C[i][j];
        if(C[i][j] == 'B') {
            cor.push_back({i,j});
            S.push_back({i+j,i,j});
            T.push_back({i-j,i,j});
            n++;
        }
    }
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());
    vector<P> test;
    rep(i,min(2,n)){
        auto[v,x,y] = S[i];
        auto[u,a,b] = T[i];
        test.push_back({x,y});
        test.push_back({a,b});
    }
    rep(i,min(2,n)){
        auto[v,x,y] = S[n-1-i];
        auto[u,a,b] = T[n-1-i];
        test.push_back({x,y});
        test.push_back({a,b});
    }
    auto[ax, ay] = bfs(test, H, W);
    cout << ax << " " << ay << endl;
}

int main(){
    fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve();
}