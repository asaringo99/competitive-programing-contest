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
ll dp[202020][2];
ll d, k;
vector<ll> A, B;

int main(){
    fast_input_output;
    cin >> n  >> d >> k ;
    rep(i,n){
        ll p, s;
        cin >> p >> s;
        if(p == 1) A.push_back(s);
        if(p == 2) B.push_back(s);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    rep(i,n+1) rep(j,2) dp[i][j] = 3e18;
    dp[0][0] = 0;
    dp[0][1] = 0;
    rep(i,n){
        {// 0
            ll tim = dp[i][0];
            auto it = lower_bound(A.begin(),A.end(),tim);
            if(it != A.end()) chmin(dp[i+1][0], *it+1);

            tim = dp[i][0] + d + i * k;
            it = lower_bound(B.begin(),B.end(),tim);
            if(it != B.end()) chmin(dp[i+1][1], *it+1);
        }
        {// 1
            ll tim = dp[i][1];
            auto it = lower_bound(B.begin(),B.end(),tim);
            if(it != B.end()) chmin(dp[i+1][1], *it+1);

            tim = dp[i][1] + d + i * k;
            it = lower_bound(A.begin(),A.end(),tim);
            if(it != A.end()) chmin(dp[i+1][0], *it+1);
        }
    }
    int res = 0;
    rep(i,n+1) rep(j,2){
        if(dp[i][j] != 3e18) res = i;
    }
    cout << res << endl;
}