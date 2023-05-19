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
typedef pair<int,int> P ;
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

int n, k ;
int A[2020][2020], B[2020][2020], S[2020][2020];

bool f(int x){
    rep(i,n) rep(j,n) B[i][j] = A[i][j] <= x ? 1 : 0;
    rep(i,n) rep(j,n) S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j] + B[i][j];
    bool ok = false;
    rep(i,n) rep(j,n){
        if(i+k>n || j+k>n) continue;
        int c = S[i+k][j+k] - S[i+k][j] - S[i][j+k] + S[i][j] ;
        if((k * k + 1) / 2 <= c) ok = true;
    }
    return ok;
}

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) rep(j,n) cin >> A[i][j];
    int lef = 0, rig = 2e9;
    while(rig - lef > 1){
        int mid = (lef + rig) / 2;
        if(f(mid)) rig = mid;
        else lef = mid;
    }
    if(f(0)) rig =  0;
    cout << rig << endl;
}