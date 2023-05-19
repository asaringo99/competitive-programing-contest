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
    int n, k;
    string S;
    cin >> n >> k >> S;
    vector<int> A;
    int sum = 0;
    for(char u : S) {
        A.push_back(u - '0');
        sum += u - '0';
    }
    int res = 1e9;
    rep(i,k){
        int c = 0, tot = 0;
        vector<int> vec;
        for(int j = i ; j < n ; j += k){
            c += A[j];
            tot++;
            if(A[j] == 1){
                vec.push_back(j);
            }
        }
        if(vec.empty()){
            chmin(res,sum);
            continue;
        }
        vector<vector<int>> dp(tot+1,vector<int>(3,1e9));
        dp[0][0] = 0;
        int b = i;
        rep(j,tot){
            int p = b + j * k;
            if(A[p] == 1){
                chmin(dp[j+1][0],dp[j][0]+1);
                chmin(dp[j+1][1],dp[j][0]);
                chmin(dp[j+1][2],dp[j][0]+1);
                chmin(dp[j+1][1],dp[j][1]);
                chmin(dp[j+1][2],dp[j][1]+1);
                chmin(dp[j+1][2],dp[j][2]+1);
            }
            else{
                chmin(dp[j+1][0],dp[j][0]);
                chmin(dp[j+1][1],dp[j][0]+1);
                chmin(dp[j+1][2],dp[j][0]);
                chmin(dp[j+1][1],dp[j][1]+1);
                chmin(dp[j+1][2],dp[j][1]);
                chmin(dp[j+1][2],dp[j][2]);
            }
        }
        chmin(res,sum-c+min({dp[tot][0],dp[tot][1],dp[tot][2]}));
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}