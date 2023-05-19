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

bool C[2020][2020];

void solve(){
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    rep(i,n) cin >> X[i] >> Y[i], X[i] += 1000, Y[i] += 1000;
    rep(i,n){
        C[X[i]][Y[i]] = true;
    }
    int res = 0;
    rep(i,n){
        int x = X[i], y = Y[i];
        bool flg = true;
        bool ok;
        ok = false;
        for(int j = x - 1; j >= 0; j--) if(C[j][y]) ok = true;
        flg &= ok;
        ok = false;
        for(int j = x + 1; j <= 2000; j++) if(C[j][y]) ok = true;
        flg &= ok;
        ok = false;
        for(int j = y - 1; j >= 0; j--) if(C[x][j]) ok = true;
        flg &= ok;
        ok = false;
        for(int j = y + 1; j <= 2000; j++) if(C[x][j]) ok = true;
        flg &= ok;
        if(flg) res++;
    }
    cout << res << endl;
}

int main(){
    fast_io
    solve();
}