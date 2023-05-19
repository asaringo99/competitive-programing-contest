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

int n, m ;
ll A[202020];
vector<int> G[202020];
P X[202020];
ll S[202020];
ll T[202020];
bool use[202020];
bool ins[202020];

bool f(ll x){
    rep(i,n) use[i] = false;
    rep(i,n) ins[i] = false;
    rep(i,n) T[i] = S[i];
    vector<int> que;
    rep(i,n) {
        auto [val, v] = X[i];
        if(val <= x) {
            ins[v] = true;
            que.push_back(v);
        }
    }
    int i = 0;
    while(i < n){
        if(i >= que.size()) {
            return false;
        }
        int v = que[i];
        use[v] = true;
        ll sum = 0;
        for(int u : G[v]){
            if(use[u]) continue;
            sum += A[u];
        }
        for(int u : G[v]){
            if(use[u]) continue;
            if(ins[u]) continue;
            T[u] -= A[v];
            if(T[u] <= x) {
                ins[u] = true;
                que.push_back(u);
            }
        }
        i++;
    }
    return true;
}

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,n) cin >> A[i];
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    rep(i,n){
        ll sum = 0;
        for(int u : G[i]){
            sum += A[u];
        }
        X[i] = {sum,i};
        S[i] = sum;
    }
    sort(X,X+n);
    ll lef = -1, rig = 1e18;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2;
        if(f(mid)) rig = mid;
        else lef = mid;
    }
    cout << rig << endl;
}