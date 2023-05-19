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

int n, m;
string S, T;
bool B[303030];

int main(){
    fast_io
    cin >> S >> T;
    n = S.size();
    m = T.size();
    bool ok = ok = true;
    B[m] = true;
    rep(i,m){
        if(S[n-1-i] != T[m-1-i]){
            if(S[n-1-i] != '?' && T[m-1-i] != '?') ok = false;
        }
        B[m - 1 - i] = ok;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    ok = true;
    rep(i,m){
        if(!(S[i] == '?' || T[i] == '?' || S[i] == T[i])){
            ok = false;
        }
        if(ok && B[i+1]){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}