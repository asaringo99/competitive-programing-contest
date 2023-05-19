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

int n, k;
int A[101010], B[101010];
bool use[101010];

int main(){
    fast_input_output
    cin >> n >> k;
    rep(i,n) cin >> A[i] >> B[i];
    ll res = 0;
    rep(i,n){
        bool ok = true;
        rep(j,30) if(!(k >> j & 1) && A[i] >> j & 1) ok = false;
        if(ok) res += B[i];
    }
    vector<int> bt;
    for(int i = 30 ; i >= 0 ; i--) if(k >> i & 1) bt.push_back(i);
    ll val = 0;
    for(int flg = 30 ; flg >= 0 ; flg--){
        rep(i,n) if(!(k >> flg & 1) && A[i] >> flg & 1) use[i] = true;
        if(!(k >> flg & 1)) continue;
        ll sum = 0;
        rep(i,n){
            if(use[i]) continue;
            if(A[i] >> flg & 1) continue;
            sum += B[i];
        }
        chmax(res,sum);
    }
    cout << res << endl;
}