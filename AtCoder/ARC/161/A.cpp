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

void solve(){
    ll n;
    cin >> n;
    rep(i,n) cin >> A[i];
    sort(A,A+n);
    vector<int> E, O;
    rep(i,n){
        if(i <= n / 2) O.push_back(A[i]);
        else E.push_back(A[i]);
    }
    vector<int> B(n);
    rep(i,n){
        if(i % 2 == 0) B[i] = O[i/2];
        else B[i] = E[i/2];
    }
    rep(i,n){
        if(i % 2 == 1){
            if(B[i-1] < B[i] && B[i] > B[i+1]) continue;
            cout << "No" << endl ;
            return;
        }
    }
    cout << "Yes" << endl ;
}

int main(){
    fast_io
    solve();
}