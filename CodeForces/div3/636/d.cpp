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
    vector<int> A(n), S(2*k+1);
    rep(i,n) cin >> A[i];
    rep(i,n/2){
        int a = A[i], b = A[n-1-i];
        if(a > b) swap(a,b);
        S[2] += 2;
        S[a+1]--;
        S[a+b]--;
        S[a+b+1]++;
        S[k+b+1]++;
    }
    int sum = 0, res = 1e9;
    rrep(i,2,2*k+1){
        sum += S[i];
        chmin(res,sum);
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}