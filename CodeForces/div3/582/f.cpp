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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    vector<char> res(n);
    rep(i,n) cin >> A[i], A[i]--;
    rep(i,n) cin >> B[i], B[i]--;
    vector<bool> use(n,false);
    vector<bool> dec(n,false);
    int sum = 0;
    int t = 0;
    rep(i,n){
        int a = A[i];
        int b = B[i];
        if(!dec[a]) res[a] = (char)('a'+t);
        if(!dec[b]) res[b] = (char)('a'+t);
        dec[a] = true;
        dec[b] = true;
        if(t == k - 1) continue;
        if(use[a]) {
            sum--;
            use[a] = false;
        }
        else {
            sum++;
            use[a] = true;
        }
        if(use[b]) {
            sum--;
            use[b] = false;
        }
        else {
            sum++;
            use[b] = true;
        }
        if(sum == 0 && i < n - 1){
            t++;
        }
    }
    if(t == k - 1) cout << "YES" << endl;
    else{
        cout << "NO" << endl;
        return;
    }
    for(char u : res) cout << u; cout << endl;
}

int main(){
    fast_input_output
    solve();
}