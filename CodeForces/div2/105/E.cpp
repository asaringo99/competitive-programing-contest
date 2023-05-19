#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n, t;
    cin >> n >> t;
    vector<vector<int>> A(n);
    rep(i,n){
        int m;
        cin >> m;
        vector<int> B(m);
        rep(j,m) cin >> B[j];
        A[i] = B;
    }
    vector<vector<int>> V(n);
    rep(i,n){
        int m = A[i].size();
        vector<int> vec = A[i];
        vector<int> U;
        rep(j,min(t,m)+1){
            ll val = 0;
            rep(k,j) val += vec[k];
            ll sum = val;
            rrep(k,1,j+1){
                sum -= vec[j-k];
                sum += vec[m-k];
                chmax(val,sum);
            }
            U.push_back(val);
        }
        V[i] = U;
    }
    vector<vector<int>> dp(n+1,vector<int>(t+1,0));
    rep(i,n){
        vector<int> vec = V[i];
        int m = vec.size();
        rep(j,t+1){
            rep(k,m){
                if(j+k>t) break;
                chmax(dp[i+1][j+k], dp[i][j] + vec[k]);
            }
        }
    }
    cout << dp[n][t] << endl;
}

int main(){
    fast_io
    solve();
}