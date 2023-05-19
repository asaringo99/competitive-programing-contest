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

int n, k;
ll A[202020];

bool f(ll x){
    ll cnt = 0, pls = 0;
    rep(i,n){
        ll mag = x - A[i] - pls;
        if(mag <= 0) continue;
        ll v = mag % (i + 1) == 0 ? mag / (i + 1) : mag / (i + 1) + 1;
        pls += v * (i + 1);
        cnt += v;
    }
    return cnt <= k;
}

int main(){
    fast_input_output
    cin >> n >> k;
    rep(i,n) cin >> A[i];
    ll lef = 0, rig = 1e18;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2;
        if(f(mid)) lef = mid;
        else rig = mid;
    }
    cout << lef << endl;
}