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

const int SQRTN = 5050;

int n, m, q;
vector<int> G[20202];
vector<int> F[20202];
bool V[20202];
bool U[20202];
unordered_multiset<int> S[20202];
int P[20202];

int main(){
    fast_input_output
    cin >> n >> m;
    rep(i,n) cin >> P[i], P[i]--;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    rep(i,n){
        if(G[i].size() > SQRTN){
            U[i] = true;
            for(int u : G[i]) {
                F[u].push_back(i);
                V[u] = true;
                S[i].insert(P[u]);
            }
        }
    }
    cin >> q;
    rep(i,q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(P[x] == P[y]){
            cout << "No" << endl ;
            continue;
        }
        bool ok = false;
        if(!U[i]){
            for(int u : G[x]){
                if(P[u] == P[y]) ok = true;
            }
            if(!ok){
                cout << "No" << endl ;
                continue;
            }
        }
        else{
            if(S[x].count(P[y])){
                ok = true;
            }
            if(!ok){
                cout << "No" << endl ;
                continue;
            }
        }
        cout << "Yes" << endl ;
        for(int u : F[x]){
            auto it = S[u].find(P[x]);
            S[u].erase(it);
        }
        P[x] = P[y];
        for(int u : F[x]){
            S[u].insert(P[x]);
        }
    }
}