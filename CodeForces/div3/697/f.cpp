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
    int n;
    cin >> n;
    vector<vector<int>> A(n,vector<int>(n)), B(n,vector<int>(n));
    rep(i,n) rep(j,n) {
        char a;
        cin >> a;
        A[i][j] = a - '0';
    }
    rep(i,n) rep(j,n) {
        char a;
        cin >> a;
        B[i][j] = a - '0';
    }
    rep(j,n) if(A[0][j] == 1) {
        rep(i,n) A[i][j] ^= 1;
    }
    rep(j,n) if(B[0][j] == 1) {
        rep(i,n) B[i][j] ^= 1;
    }
    rrep(i,1,n){
        if(A[i][0] != B[i][0]) {
            rep(j,n) A[i][j] ^= 1;
        }
    }
    rep(i,n) rep(j,n) if(A[i][j] != B[i][j]) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}