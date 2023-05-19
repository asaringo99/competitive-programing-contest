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

int z ;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int,int>>> G(n);
    vector<int> A(n,0);
    vector<bool> used(n,false);
    rep(i,q){
        int a, b, x;
        cin >> a >> b >> x;
        a--; b--;
        if(a == b){
            A[a] = x;
            used[a] = true;
            continue;
        }
        if(a < b) swap(a,b);
        G[a].push_back({b,x});
        G[b].push_back({a,x});
    }
    rep(bt,30){
        vector<bool> use(n, false);
        rep(v,n){
            if(used[v]) continue;
            for(auto p : G[v]){
                auto[u,x] = p;
                if(!(x >> bt & 1)){
                    use[v] = true;
                    use[u] = true;
                }
            }
        }
        rep(v,n) {
            if(used[v]) continue;
            if(!use[v]) A[v] |= 1 << bt;
        }
        rep(v,n){
            if(used[v]) continue;
            if(use[v]) continue;
            bool ok = true;
            for(auto p : G[v]){
                auto[u,x] = p;
                if(!(A[u] >> bt & 1)) ok = false;
            }
            if(ok) A[v] ^= 1 << bt;
        }
    }
    rep(i,n) cout << A[i] << " "; cout << endl;
}

int main(){
    fast_input_output
    solve();
}