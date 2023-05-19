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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int n;
ll A[505050], B[505050];
ll X[50][505050];
bitset<505050> S[40], T[40];

int main(){
    fast_io
    cin >> n;
    size_t N = n;
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    rep(j,n){
        S[A[j]][j] = 1;
        T[B[j]][j] = 1;
    }
    ll ans = 0;
    rep(i,n){
        ll res = 0;
        rep(x,32){
            rep(y,32){
                auto U = S[x] & T[y];
                res += (ll)(x | y) * U.count();
            }
        }
        chmax(ans,res);
        rep(x,4){
            int o = S[x][n-1];
            S[x] <<= 1;
            S[x][0] = o;
        }
    }
    cout << ans << endl;
}