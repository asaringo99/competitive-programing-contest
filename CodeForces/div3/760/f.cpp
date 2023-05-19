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
ll x, y;

unordered_map<ll,bool> mp;

bool rec(ll x){
    if(x > 1000000000000000000LL) return false;
    if(x == y) return true;
    if(mp[x]) return false;
    mp[x] = true;
    if(bit_count(x) > bit_count(y)) return false;
    ll res = 0;
    int k = 0;
    for(int i = 0 ; i < 62 ; i++) if(x >> i & 1) k = i + 1;
    for(int i = 0 ; i < k ; i++){
        res *= 2;
        res += (x >> i & 1);
    }
    x *= 2;
    x += 1;
    ll val = 0;
    int l = 0;
    for(int i = 0 ; i < 62 ; i++) if(x >> i & 1) l = i + 1;
    for(int i = 0 ; i < l ; i++){
        val *= 2;
        val += (x >> i & 1);
    }
    return rec(res) | rec(val);
}

void solve(){
    cin >> x >> y;
    if(rec(x)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    fast_input_output
    solve();
}