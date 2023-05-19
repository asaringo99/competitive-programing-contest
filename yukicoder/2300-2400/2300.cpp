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

int n;
ll A[202020];
bool B[30][202020];
int nextv[30][202020];

int main(){
    fast_input_output
    cin >> n;
    rep(i,n) cin >> A[i];
    rep(i,n) rep(j,30) if(A[i] >> j & 1) B[j][i] = true;
    rep(i,30) nextv[i][n] = n;
    for(int i = n - 1; i >= 0; i--){
        rep(j,30){
            nextv[j][i] = nextv[j][i+1];
            if(B[j][i]) nextv[j][i] = i;
        }
    }
    ll res = 0;
    rep(i,n){
        rep(j,30){
            int nv = nextv[j][i];
            if(nv == n) continue;
            res += (ll)(n - nv) * (ll)1 << j;
        }
    }
    cout << res << endl;
}