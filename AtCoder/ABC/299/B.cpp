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

ll n, t;
ll C[202020];
ll R[202020];

int main(){
    fast_io
    cin >> n >> t;
    vector<int> V;
    rep(i,n) cin >> C[i];
    rep(i,n){
        if(C[i] == t) V.push_back(i);
    }
    rep(i,n) cin >> R[i];
    if(V.empty()){
        t = C[0];
        int k = -1, val = 0;
        rep(i,n){
            if(C[i] != t) continue;
            if(R[i] > val){
                val = R[i];
                k = i;
            }
        }
        cout << k + 1 << endl;
    }
    else{
        int k = -1, val = 0;
        rep(i,V.size()){
            int p = V[i];
            if(R[p] > val){
                val = R[p];
                k = p;
            }
        }
        cout << k + 1 << endl;
    }
}