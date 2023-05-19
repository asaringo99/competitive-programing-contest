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

int n, k, q;
ll A[202020];

int main(){
    fast_io
    cin >> n >> k;
    rep(i,n) cin >> A[i];
    vector<vector<int>> S(k,vector<int>(n+1));
    rrep(d,1,k+1){
        rrep(i,1,n+1){
            S[d%k][i] = S[d%k][i-1];
            if(i % k == d%k) S[d%k][i] += A[i-1];
        }
    }
    // rep(d,k){
    //     rep(i,n+1) cout << S[d][i] << " "; cout << endl;
    // }
    cin >> q;
    rep(i,q){
        int l, r;
        cin >> l >> r;
        vector<ll> B(k);
        rrep(i,l,l+k){
            B[i-l] = S[i%k][r] - S[i%k][i-1];
            // cout << B[i-l] << " ";
        }
        // cout << endl;
        bool ok = true;
        rep(t,k-1){
            if(B[t] != B[t+1]) ok = false;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}