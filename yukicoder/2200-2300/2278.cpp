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
#define all(a) a.begin(), a.end()
#define endl "\n"

int n;
string S;

int main(){
    fast_input_output
    cin >> n >> S;
    vector<vector<ll>> A(n+1,vector<ll>(3,0));
    rep(i,n){
        A[i+1][0] = A[i][0];
        A[i+1][1] = A[i][1];
        A[i+1][2] = A[i][2];
        if(S[i] == '?') A[i+1][0]++;
        if(S[i] == 'A') A[i+1][1]++;
        if(S[i] == 'C') A[i+1][2]++;
    }
    ll res = 0;
    ll c = 0;
    for(int i = n - 1; i >= 0; i--){
        if(S[i] == 'A') res += c;
        else c++;
    }
    ll a = 0;
    ll sum = res;
    rep(i,n){
        if(S[i] == 'a') a++;
        if(S[i] == '?'){
            sum -= a;
            sum -= A[i][1];
            sum += A[n][2] - A[i][2];
            sum += A[n][0] - A[i+1][0];
            chmax(res,sum);
            a++;
        }
    }
    cout << res << endl;
}