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

void solve(){
    ll n;
    cin >> n;
    vector<int> A(n);
    rep(i,n) cin >> A[i], A[i]--;
    vector<pair<int,int>> X(n);
    rep(i,n){
        X[i] = {A[i],i};
    }
    sort(all(X));
    set<int> st;
    st.insert(n);
    int res = 0;
    rep(i,n){
        auto[ord, id] = X[i];
        auto it = st.lower_bound(id);
        if(*it != n) continue;
        res++;
        st.insert(id);
    }
    cout << res << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}