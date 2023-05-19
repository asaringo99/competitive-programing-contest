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

int z ;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> A(n), S(n+1,0);
    rep(i,n) cin >> A[i];
    sort(A.begin(),A.end());
    rep(i,n) S[i+1] = S[i] + A[i];
    ll res = 2e18;
    rep(i,n){
        ll a = A[i];
        auto lt = lower_bound(A.begin(),A.end(),a);
        auto rt = upper_bound(A.begin(),A.end(),a);
        ll rem = k - (rt - lt);
        if(rem <= 0) {
            chmin(res,0LL);
            break;
        }
        int l = lt - A.begin();
        int r = rt - A.begin();
        ll lcnt = (a - 1) * l - S[l];
        ll rcnt = (S[n] - S[r]) - ((a + 1) * (n - r));
        if(l >= rem) chmin(res,lcnt+rem);
        if(n - r >= rem) chmin(res,rcnt+rem);
        chmin(res,rcnt+lcnt+rem);
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    solve();
}