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
ll A[5050];
unordered_map<ll,ll> dp[5050];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    sort(A,A+n);
    dp[0][0] = 1;
    rrep(i,1,n){
        dp[i][0] = 1;
        rep(j,i){
            ll k = A[i] - A[j];
            for(auto [key, val] : dp[j]){
                ll g = gcd(key, k);
                if(g == 1 || g == 2) continue;
                chmax(dp[i][g], val + 1);
            }
        }
    }
    ll res = 0, ans = 0;
    rep(i,n){
        for(auto [key, val] : dp[i]){
            if(key <= 2) continue;
            if(res <= val){
                res = val;
                ans = key;
            }
        }
    }
    ans = res > n / 2 ? ans : -1;
    cout << ans << endl;
}