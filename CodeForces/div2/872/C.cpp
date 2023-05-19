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
    int n, m;
    cin >> n >> m;
    vector<int> A;
    vector<bool> B(m,false);
    int L = 0, R = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a == -1) L++;
        if(a == -2) R++;
        if(a > 0) {
            if(B[a-1]) continue;
            B[a-1] = true;
            A.push_back(a-1);
        }
    }
    sort(all(A));
    int k = A.size();
    int res = 0;
    rep(i,k){
        int x = min(A[i],i+L);
        int y = min(m-1-A[i],k-1-i+R);
        // cout << x << " " << y << endl;
        chmax(res,x+y+1);
    }
    chmax(res,k+L);
    chmax(res,k+R);
    chmin(res,m);
    cout << res << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}