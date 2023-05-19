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

int n, s ;
bool dp[101][10101];
int pre[101][10101];
int A[101], B[101];

int main(){
    fast_input_output
    cin >> n >> s ;
    rep(i,n) cin >> A[i] >> B[i];
    dp[0][0] = true;
    rep(i,n){
        rep(j,s+1){
            if(!dp[i][j]) continue;
            dp[i+1][j+A[i]] = true;
            dp[i+1][j+B[i]] = true;
            pre[i+1][j+A[i]] = j;
            pre[i+1][j+B[i]] = j;
        }
    }
    if(!dp[n][s]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int k = n;
    vector<char> res;
    while(k > 0){
        int j = pre[k][s];
        k--;
        if(s - j == A[k]) res.push_back('H');
        else res.push_back('T');
        s = j;
    }
    reverse(res.begin(),res.end());
    for(char u: res) cout << u; cout << endl;
}