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

int n, q;

int P[202020];
int A[202020];

int dfs(int v, int &kind){
    if(A[v] != -1) return A[v];
    if(P[v] == -1) return A[v] = kind++;
    return A[v] = dfs(P[v], kind);
}

int main(){
    fast_input_output
    cin >> n >> q;
    rep(i,n) cin >> P[i];
    rep(i,n) A[i] = -1;
    rep(i,n) if(P[i] != -1) P[i]--;
    int kind = 0;
    rep(i,q){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(dfs(a, kind) == dfs(b, kind)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}