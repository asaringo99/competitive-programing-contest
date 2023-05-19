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
#define all(a) a.begin(), a.end()
#define endl "\n"

int n ;
ll A[202020];
bool C[101];

ll dfs(vector<pair<int,ll>> &I, int c){
    if(c < 0){
        ll res = 1e10;
        for(auto [i,val]: I) {
            chmin(res,val);
        }
        return res;
    }
    bool ok1 = true;
    bool ok2 = true;
    for(auto[i,val] : I){
        if(!(val >> c & 1)) ok1 = false;
        if(val >> c & 1) ok2 = false;
    }
    if(ok1){
        rep(i,I.size()){
            I[i].second ^= (1 << c);
        }
        return dfs(I,c-1);
    }
    if(ok2){
        return dfs(I,c-1);
    }
    vector<pair<int,ll>> S, T;
    for(auto [i,val] : I){
        if(val >> c & 1){
            S.push_back({i,val});
        }
        else{
            T.push_back({i,(val ^ (1 << c))});
        }
    }
    if(S.empty() && T.empty()) return 1e10;
    if(S.empty()) return dfs(T,c-1);
    if(T.empty()) return dfs(S,c-1);
    ll val = min(dfs(S,c-1), dfs(T,c-1));
    return val;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    vector<pair<int,ll>> X;
    rep(i,n) X.push_back({i,A[i]});
    int y = 0;
    rep(x,31){
        bool ok = true;
        rep(i,n){
            if(A[i] >> x & 1) y = x;
            if(!(A[i] >> x & 1)) ok = false;
        }
        if(ok) C[x] = true;
    }
    cout << dfs(X,y) << endl;
}