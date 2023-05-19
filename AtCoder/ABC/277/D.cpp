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

int n, m ;
ll A[402020];

int main(){
    fast_input_output
    cin >> n >> m ;
    ll res = 0;
    rep(i,n) cin >> A[i], res += A[i];
    sort(A,A+n);
    rep(i,n) A[i+n] = A[i];
    n = 2 * n;
    // rep(i,n) cout << A[i] << " "; cout << endl;
    int lef = 0, rig = 0;
    ll ans = res;
    while(rig < n){
        lef = rig;
        ll sum = A[rig];
        while(rig < n - 1 && rig - lef < n/2 - 1 && (A[rig+1] == A[rig] || (A[rig] + 1) % m == A[rig+1])){
            sum += A[rig+1];
            rig++;
        }
        rig++;
        // cout << sum << endl;
        chmin(ans,res-sum);
    }
    cout << ans << endl;
}