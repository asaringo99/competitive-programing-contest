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
    int n;
    cin >> n;
    vector<vector<int>> A(n);
    rep(i,n){
        int t;
        cin >> t;
        vector<int> B(t);
        rep(j,t) cin >> B[j];
        A[i] = B;
    }
    set<int> st, res;
    vector<int> ans;
    for(int i = n - 1; i >= 0; i--){
        vector<int> B = A[i];
        bool ok = false;
        for(int u: B) if(st.count(u) == 0) ok = true;
        if(!ok){
            cout << -1 << endl;
            return;
        }
        for(int u: B){
            if(st.count(u)) continue;
            if(res.count(u)) continue;
            res.insert(u);
            ans.push_back(u);
            break;
        }
        for(int u: B) st.insert(u);
    }
    if(res.size() != n){
        cout << -1 << endl;
        return;
    }
    reverse(all(ans));
    for(int u: ans) cout << u << " "; cout << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}