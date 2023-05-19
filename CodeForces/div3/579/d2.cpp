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
int n, m;
string S, T, U;

int next_s[202020][26];
int next_t[202020][26];

void f(){
    for(int i = 0 ; i < 26 ; i++){
        next_s[n][i] = n;
        next_t[n][i] = n;
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 26 ; j++){
            next_s[i][j] = next_s[i+1][j];
            next_t[i][j] = next_t[i+1][j];
        }
        next_s[i][S[i]-'a'] = i;
        next_t[i][T[i]-'a'] = i;
    }
}

void solve(){
    cin >> S >> U;
    n = S.size();
    m = U.size();
    T = "";
    rep(i,n) T += S[n-1-i];
    f();
    int res = 0;
    int k = 0;
    vector<int> A, B;
    rep(i,m){
        k = next_s[k][U[i]-'a'];
        A.push_back(k);
        k++;
    }
    chmax(res,n-k);
    int t = 0;
    rep(i,m){
        t = next_t[t][U[m-1-i]-'a'];
        B.push_back(t);
        t++;
    }
    chmax(res,n-t);
    rep(i,m-1){
        chmax(res,n-B[m-2-i]-A[i]-2);
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    solve();
}