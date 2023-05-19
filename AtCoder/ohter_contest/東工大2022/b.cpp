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

vector<int> f(int x){
    vector<int> vec, A;
    while(x > 0){
        vec.push_back(x % 10);
        x /= 10;
    }
    int n = vec.size();
    A.resize(n);
    rep(i,n) A[i] = i;
    vector<int> ret;
    do{
        ll sum = 0;
        rep(i,n) {
            sum *= 10;
            sum += vec[A[i]];
        }
        ret.push_back(sum);
    } while (next_permutation(A.begin(), A.end()));
    return ret;
}

int n, x ;
ll dp[201][101010];
int A[201];

int main(){
    fast_input_output
    cin >> n >> x;
    rep(i,n) cin >> A[i];
    rep(i,n+1) rep(j,10101) dp[i][j] = -1e16;
    dp[0][x] = 0;
    rep(i,n){
        rep(j,10010){
            vector<int> V = f(j);
            chmax(dp[i+1][j], dp[i][j]);
            for(int u : V){
                if(u - A[i] >= 0) chmax(dp[i+1][u - A[i]], dp[i][j] + 1);
            }
        }
    }
    ll res = 0;
    rep(i,10101) chmax(res,dp[n][i]);
    cout << res << endl;
}