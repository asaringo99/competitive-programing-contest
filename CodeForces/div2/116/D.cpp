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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> X(101010);
    vector<int> A(n);
    rep(i,n) cin >> A[i], X[A[i]-1].push_back(i);
    int res = 1;
    rep(i,101010){
        auto V = X[i];
        if(V.empty()) continue;
        int N = V.size();
        int lef = 0, rig = 0;
        int sum = 0;
        while(rig < N-1){
            while(rig < N-1 && sum <= k){
                chmax(res, rig - lef + 1);
                sum += V[rig+1] - V[rig] - 1;
                rig++;
            }
            while(lef < N-1 && sum > k){
                sum -= V[lef+1] - V[lef] - 1;
                lef++;
            }
            chmax(res, rig - lef + 1);
        }
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}