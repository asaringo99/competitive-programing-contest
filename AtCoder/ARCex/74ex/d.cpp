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

priority_queue<ll,vector<ll>,greater<ll>> lef;
priority_queue<ll> rig;

int n ;
ll A[303030];
ll B[101010];
ll C[101010];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,3*n) cin >> A[i];
    ll l = 0, r = 0;
    rep(i,n) lef.push(A[i]), l += A[i];
    rep(i,n){
        B[i] = l;
        l += A[i+n];
        lef.push(A[i+n]);
        l -= lef.top();
        lef.pop();
    }
    B[n] = l;
    rep(i,n) rig.push(A[3*n-1-i]), r += A[3*n-1-i];
    rep(i,n){
        C[i] = r;
        r += A[2*n-1-i];
        rig.push(A[2*n-1-i]);
        r -= rig.top();
        rig.pop();
    }
    C[n] = r;
    ll res = -1e18;
    rep(i,n+1){
        chmax(res,B[i]-C[n-i]);
    }
    cout << res << endl;
}