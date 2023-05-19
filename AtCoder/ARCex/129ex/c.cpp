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


int n ;
map<P,bool> dp[55];

int main(){
    // fast_input_output
    dp[0][P(0,0)] = true;
    cin >> n ;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        for(auto it : dp[i]){
            auto[p, bl] = it;
            auto[x, y] = p;
            dp[i+1][P(gcd(x,a),gcd(y,b))] = true;
            dp[i+1][P(gcd(x,b),gcd(y,a))] = true;
        }
    }
    ll res = 0;
    for(auto it : dp[n]){
        auto[p, bl] = it;
        auto[x, y] = p;
        chmax(res,lcm(x,y));
    }
    cout << res << endl;
}