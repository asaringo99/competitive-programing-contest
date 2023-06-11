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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

char C[1010][1010];

void solve(){
    int H, W;
    cin >> H >> W;
    int a, b;
    int sx = 1e9, sy = 1e9, gx = -1, gy = -1;
    rep(i,H) rep(j,W) cin >> C[i][j];
    rep(i,H){
        rep(j,W){
            if(C[i][j] == '#'){
                chmin(sx,i);
                chmax(gx,i);
                chmin(sy,j);
                chmax(gy,j);
            }
        }
    }
    rrep(i,sx,gx+1) rrep(j,sy,gy+1){
        if(C[i][j] == '.'){
            cout << i + 1 << " " << j + 1 << endl;
            return;
        }
    }
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}