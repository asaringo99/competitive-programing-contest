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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int n ;

void solve(){
    ll a, b;
    cin >> a >> b;
    ll res = 1e18;
    ll A = a;
    if(a <= 100000){
        ll da = 0;
        while(da < res){
            ll c = b % a;
            chmin(res,da+(a-c)%a);
            da++;
            a++;
        }
    }
    a = A;
    if(a >= 1000){
        rrep(k,1,100000){
            ll c = b - a * k;
            if(c % k == 0) chmin(res,abs(c/k));
            else if(c < 0){
                chmin(res,abs(c));
            }
            else{
                ll x = c / k + 1;
                ll y = x * k - c;
                chmin(res,x+y);
            }
        }
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    int t;
    cin >> t;
    rep(i,t) solve();
}