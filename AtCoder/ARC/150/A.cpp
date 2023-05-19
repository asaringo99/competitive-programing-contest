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


void solve(){
    int n, k ;
    string s;
    cin >> n >> k >> s;
    vector<int> S(n+10,0);
    vector<int> T(n+10,0);
    vector<int> U(n+10,0);
    rep(i,n){
        S[i+1] = S[i];
        T[i+1] = T[i];
        U[i+1] = U[i];
        if(s[i] == '1') S[i+1]++;
        if(s[i] == '0') T[i+1]++;
        if(s[i] == '?') U[i+1]++;
    }
    int res = 0;
    rep(i,n){
        if(i + k > n) continue;
        if(T[i+k] - T[i] > 0) continue;
        if(i > 0 && s[i-1] == '1') continue;
        if(i + k < n && s[i+k] == '1') continue;
        res++;
    }
    if(res == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    // fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve();
}