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

int n;
string S, T;
int X[30];
int Y[30];

int main(){
    fast_io
    string A = "atcoder";
    cin >> S >> T;
    for(char u : S) {
        if(u == '@') X[26]++;
        else X[u-'a']++;
    }
    for(char u : T) {
        if(u == '@') Y[26]++;
        else Y[u-'a']++;
    }
    rep(i,26){
        int x = min(X[i],Y[i]);
        X[i] -= x;
        Y[i] -= x;
    }
    bool ok = true;
    rep(i,26){
        if(X[i] > 0){
            for(char u : A) if(i == u - 'a'){
                Y[26] -= X[i];
                X[i] = 0;
                if(Y[26] < 0){
                    cout << "No" << endl ;
                    return 0;
                }
            }
        }
        if(Y[i] > 0){
            for(char u : A) if(i == u - 'a'){
                X[26] -= Y[i];
                Y[i] = 0;
                if(X[26] < 0){
                    cout << "No" << endl ;
                    return 0;
                }
            }
        }
        if(X[i] > 0 || Y[i] > 0){
            cout << "No" << endl ;
            return 0;
        }
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}