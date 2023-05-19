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

void solve(){
    int n;
    string S;
    cin >> n >> S;
    if(S == "110" || S == "011"){
        cout << -1 << endl;
        return;
    }
    if(S == "0110"){
        cout << 3 << endl;
        return;
    }
    int cnt = 0;
    rep(i,n) if(S[i] == '1') cnt++;
    if(cnt == 0){
        cout << 0 << endl;
        return;
    }
    if(cnt & 1){
        cout << -1 << endl;
        return;
    }
    int c = 0, k, s;
    bool flg = true;
    rep(i,n){
        if(S[i] == '1') {
            if(flg){
                flg = false;
                s = i;
            }
            c++;
        }
        if(c == cnt / 2 + 1){
            k = i;
            break;
        }
    }
    if(abs(s-k) == 1){
        cout << 2 << endl;
        return;
    }
    cout << cnt / 2 << endl;
}

int main(){
    fast_input_output
    int t;
    cin >> t;
    rep(i,t) solve();
}