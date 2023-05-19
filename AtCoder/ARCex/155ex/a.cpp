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

void solve(){
    ll n;
    ll k;
    string S;
    cin >> n >> k >> S;
    ll res = 4e18, ans = 4e18;
    for(ll i = 1; i * i <= n; i++){
        if(n % i != 0) continue;
        string W = "";
        for(ll s = 0; s < i; s++) W += S[s];
        bool ok = true;
        for(ll s = 0; s < i; s++) if(W[s] != W[i-1-s]) ok = false;
        for(ll s = 0; s < n; s += i){
            for(ll t = 0; t < i; t++){
                if(S[s+t] != W[t]) ok = false;
            }
        }
        if(ok) chmin(res,i);
        if(n % (2 * i) == i){
            ll p = 2 * i;
            W = "";
            for(ll s = 0; s < p; s++) W += S[s];
            ok = true;
            for(ll s = 0; s < p; s++) if(W[s] != W[p-1-s]) ok = false;
            for(ll s = 0; s < n; s += p){
                if(s + p > n) continue;
                for(ll t = 0; t < p; t++){
                    if(S[s+t] != W[t]) ok = false;
                }
            }
            for(ll s = 0; s < i; s++) if(S[n-i+s] != W[s]) ok = false;
            if(ok) chmin(ans,i);
        }
        W = "";
        ll j = n / i;
        for(ll s = 0; s < j; s++) W += S[s];
        ok = true;
        for(ll s = 0; s < j; s++) if(W[s] != W[j-1-s]) ok = false;
        for(ll s = 0; s < n; s += j){
            for(ll t = 0; t < j; t++){
                if(S[s+t] != W[t]) ok = false;
            }
        }
        if(ok) chmin(res,j);
        if(n % (2 * j) == j){
            ll p = 2 * j;
            W = "";
            if(p > n){
                chmin(ans,j);
                continue;
            }
            for(ll s = 0; s < p; s++) W += S[s];
            ok = true;
            for(ll s = 0; s < p; s++) if(W[s] != W[p-1-s]) ok = false;
            for(ll s = 0; s < n; s += p){
                if(s + p > n) continue;
                for(ll t = 0; t < p; t++){
                    if(S[s+t] != W[t]) ok = false;
                }
            }
            for(ll s = 0; s < j; s++) if(S[n-j+s] != W[s]) ok = false;
            if(ok) chmin(ans,j);
        }
    }
    if(k % res == 0 || (k - ans) % (2 * ans) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main(){
    fast_io
    ll t;
    cin >> t;
    rep(i,t) solve();
}

// abcde edcba abcde edcba
// S := abccbaa
// T := aabccba ----------- aabccba

// T := aabccba ----- abccbaaaabccba