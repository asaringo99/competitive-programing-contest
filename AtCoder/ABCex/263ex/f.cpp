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

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int n ;
ll C[1<<16][16];
ll dp[16][1<<16];
ll ep[16][1<<16];

ll rec(int winner, int dep, int block){
    if(dep == n) return 0;
    if(winner != -1 && ep[dep][winner] != -1) return ep[dep][winner];
    if(winner == -1 && dp[dep][block] != -1) return dp[dep][block];
    int c = powll(2,dep);
    int cnt = (1 << n) / c;
    int s = (1 << n) / c * block;
    int t = s + cnt;
    if(winner == -1){
        ll res = 0;
        for(int i = s ; i < t ; i++){
            if(i < (s + t) / 2) chmax(res, rec(i,dep+1,2*block) + rec(-1,dep+1,2*block+1) + C[i][dep]);
            else chmax(res, rec(-1,dep+1,2*block) + rec(i,dep+1,2*block+1) + C[i][dep]);
        }
        return dp[dep][block] = res;
    }
    ll res = 0;
    if(winner < (s + t) / 2) res = rec(winner, dep+1, 2*block) + rec(-1, dep+1, 2*block+1);
    else res = rec(-1, dep+1, 2*block) + rec(winner, dep+1, 2*block+1);
    return ep[dep][winner] = res;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(S,1<<n) rep(i,n) cin >> C[S][n-1-i];
    rep(S,1<<n) rep(i,n) dp[i][S] = -1;
    rep(S,1<<n) rep(i,n) ep[i][S] = -1;
    cout << rec(-1,0,0) << endl;
}