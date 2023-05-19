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

void solve(){
    int n, q;
    cin >> n;
    vector<ll> A(n);
    ll tot = 0;
    rep(i,n) cin >> A[i], tot += A[i];
    cin >> q;
    vector<ll> X(n+1,-1);
    ll sum = 0;
    ll maxval = 0;
    ll tall = 0;
    rep(i,n){
        sum += A[i];
        ll val = sum / (i + 1);
        ll ret = tot / (i + 1);
        if(sum % (i + 1) != 0) val++;
        if(tot % (i + 1) != 0) ret++;
        chmax(maxval,val);
        X[n-i] = max(maxval,ret);
    }
    rep(i,q){
        int a;
        cin >> a;
        auto it = upper_bound(X.begin(),X.end(),a); it--;
        int res = it - X.begin();
        res = n + 1 - res;
        if(res == n + 1) cout<< -1 << endl;
        else cout << res << endl;
    }
}

int main(){
    fast_input_output
    solve();
}