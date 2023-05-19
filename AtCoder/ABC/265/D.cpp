#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
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
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"
#define pt(a) cout << a << endl

ll n, p, q, r ;
ll A[202020], S[202020];

int main(){
    fast_input_output
    cin >> n >> p >> q >> r ;
    bool ok = false;
    rep(i,n) cin >> A[i], S[i+1] = S[i] + A[i];
    rep(i,n){
        auto it = lower_bound(S,S+n+1,S[i]+p);
        if(*it != S[i]+p) continue;
        int j = it - S;
        it = lower_bound(S,S+n,S[j]+q);
        if(*it != S[j]+q) continue;
        int k = it - S;
        it = lower_bound(S,S+n,S[k]+r);
        if(*it != S[k]+r) continue;
        ok = true;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}