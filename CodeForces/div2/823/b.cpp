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
int n;

void solve(){
    cin >> n;
    vector<ll> X(n), T(n);
    rep(i,n) cin >> X[i];
    rep(i,n) cin >> T[i];
    auto f = [&](ld x){
        ld res = 0;
        rep(i,n){
            ld y = X[i], t = T[i];
            chmax(res,abs(x-y)+t);
        }
        return res;
    };
    ld lef = 0, rig = 1e9;
    int cnt = 0;
    while(cnt < 1000){
        ld lm = (2 * lef + rig) / 3, rm = (lef + 2 * rig) / 3;
        if(f(lm) > f(rm)) lef = lm;
        else rig = rm;
        cnt++;
    }
    cout << fixed << setprecision(15) << lef << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}