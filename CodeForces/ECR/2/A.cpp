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
    string S;
    cin >> S;
    n = S.size();
    rep(i,n) if(S[i] == ';') S[i] = ',';
    vector<bool> B(n, false);
    string A = "";
    string Y = "";
    string X = "";
    bool ok = true;
    rep(i,n){
        if(S[i] == ','){
            if(S[i-1] == ',') ok = false;
            if(ok) A += X + ',';
            else Y += X + ',';
            ok = true;
            X = "";
            if(i == n - 1) ok = false;
            continue;
        }
        X += S[i];
        int k = S[i] - 'a';
        if(0 <= k && k < 26) ok = false;
        if(S[i] == '0'){
            if(i < n - 1 && S[i+1] != ',') ok = false;
        }
    }
    if(ok) A += X + ',';
    else Y += X + ',';
    if(A.size() > 0) A.pop_back();
    if(Y.size() > 0) Y.pop_back();
    if(A.size() > 0) cout << '"' << A << '"' << endl;
    else cout << '-' << endl;
    if(Y.size() > 0) cout << '"' << Y << '"' << endl;
    else cout << "-" << endl;
}

int main(){
    fast_io
    solve();
}