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
    vector<int> A(202020);
    rep(i,n) {
        int a;
        cin >> a;
        A[a]++;
    }
    vector<int> dp(202020,0);
    vector<int> use(202020,false);
    rrep(i,1,202020){
        if(A[i] > 0) use[i] = true;
        dp[i] += A[i];
        int j = 2;
        while(i * j <= 202020){
            dp[i*j] = max(dp[i*j],dp[i]);
            j++;
        }
    }
    int res = 0;
    rep(i,202020) if(use[i]) chmax(res,dp[i]);
    cout << n - res << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}