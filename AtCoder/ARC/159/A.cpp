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

ll n;
ll k;
int q;

ll A[101][101];
ll D[101][101];

void f(){
    rep(k,n){
        rep(i,n) rep(j,n){
            chmin(D[i][j],D[i][k]+D[k][j]);
        }
    }
}

int main(){
    fast_io
    cin >> n >> k;
    rep(i,n) rep(j,n) cin >> A[i][j];
    rep(i,n) rep(j,n){
        if(A[i][j] == 0) D[i][j] = 1e18;
        else D[i][j] = 1;
    }
    f();
    cin >> q;
    rep(i,q){
        ll s, t;
        cin >> s >> t;
        s--; t--;
        ll res = D[s%n][t%n];
        if(res == 1e18) res = -1;
        cout << res << endl;
    }
}