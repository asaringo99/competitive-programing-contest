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

ll A[202020];
ll S[202020];
int n, q;

void solve(){
    cin >> n;
    rep(i,n) cin >> A[i];
    rep(i,n){
        S[i+1] = S[i];
        if(i % 2 == 0 && i >= 2){
            S[i+1] += A[i] - A[i-1];
        }
    }
    // rep(i,n+1) cout << S[i] << " "; cout << endl;
    cin >> q;
    rep(i,q){
        int l, r;
        cin >> l >> r;
        auto rt = upper_bound(A,A+n,r);
        auto lt = upper_bound(A,A+n,l);
        int rid = rt - A;
        int lid = lt - A;
        ll sum = S[rid] - S[lid+1];
        if(lid % 2 == 0) sum += A[lid] - l;
        if(rid % 2 == 0) sum += r - A[rid - 1];
        cout << sum << endl;
        // cout << lid << " " << rid << " " << sum << endl;
    }
}

int main(){
    fast_io
    // int t;
    // cin >> t;
    // rep(i,t) solve();
    solve();
}