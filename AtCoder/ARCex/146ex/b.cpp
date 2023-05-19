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

int k;

tuple<bool,vector<ll>,int> f(vector<ll> A, int bi, ll m){
    int M = m;
    int n = A.size();
    vector<ll> B, C;
    rep(i,n){
        if(A[i] >> bi & 1) {
            A[i] ^= 1 << bi;
            B.push_back(A[i]);
        }
        else C.push_back(A[i]);
    }
    int c = C.size();
    if(B.size() >= k) return {true,B,m};
    priority_queue<ll,vector<ll>,greater<ll>> que;
    rep(i,c){
        que.push((1LL << bi) - C[i]);
    }
    while(B.size() < k){
        ll v = que.top(); que.pop();
        m -= v;
        B.push_back(0);
    }
    if(m >= 0) return {true,B,m};
    else return {false,A,M};
}

int n, m;
vector<ll> A;

int main(){
    fast_input_output
    cin >> n >> m >> k ;
    A.resize(n);
    rep(i,n) cin >> A[i];
    ll res = 0;
    for(int i = 31 ; i >= 0 ; i--){
        auto[bl,vec,M] = f(A,i,m);
        if(bl) res ^= 1 << i;
        A = vec;
        m = M;
    }
    cout << res << endl;
}