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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if(a == b){
        chmin(x,y);
        cout << x / a << endl;
        return;
    }
    if(x < y) swap(x,y);
    if(a < b) swap(a,b);
    ll d = abs(a - b);
    ll v = x - y;
    ll c = v / d;
    if(x - c * a < 0 && y - c * b < 0){
        cout << min(x / a, y / b) << endl;
        return;
    }
    if(x - c * a < 0){
        cout << x / a << endl;
        return;
    }
    if(y - c * b < 0){
        cout << y / b << endl;
        return;
    }
    x -= c * a;
    y -= c * b;
    ll e = a + b;
    ll f = y / e;
    c += 2 * f;
    x -= e * f;
    y -= e * f;
    if(x - a >= 0 && y - b >= 0) c++;
    cout << c << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}