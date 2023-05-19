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

int n ;
int C[1010][1010];

int main(){
    fast_input_output
    cin >> n ;
    if(n % 2 == 0){
        set<int> o, e;
        rrep(i,1,n*n+1) {
            if(i % 2 == 0) e.insert(i);
            else o.insert(i);
        }
        rep(i,n) {
            C[n/2-1][i] = 2 * i + 1;
            o.erase(2*i+1);
        }
        int k;
        for(int i = n * n ; i >= 0 ; i -= 2){
            if((i + 1) % 5 == 0){
                k = i;
                break;
            }
        }
        rep(i,n) {
            C[n/2][i] = k - 2*i;
            e.erase(k-2*i);
        }
        rep(i,n/2-1) rep(j,n) {
            auto it = o.begin();
            C[i][j] = *it;
            o.erase(it);
        }
        rrep(i,n/2+1,n) rep(j,n) {
            auto it = e.begin();
            C[i][j] = *it;
            e.erase(it);
        }
        rep(i,n){
            rep(j,n) cout << C[i][j] << " "; cout << endl;
        }
        return 0;
    }
    if(n == 3){
        C[0][0] = 9;
        C[0][1] = 3;
        C[0][2] = 1;
        C[1][0] = 5;
        C[1][1] = 7;
        C[1][2] = 8;
        C[2][0] = 4;
        C[2][1] = 2;
        C[2][2] = 6;
        rep(i,n){
            rep(j,n) cout << C[i][j] << " "; cout << endl;
        }
        return 0;
    }
    set<int> o, e;
    rrep(i,1,n*n+1) {
        if(i % 2 == 0) e.insert(i);
        else o.insert(i);
    }
    rep(i,n/2+1){
        C[n/2][i] = 2*i+1;
        o.erase(2*i+1);
    }
    int val = 2 * (n / 2) + 1 + 10;

    // cout << val << endl;

    rrep(i,n/2+1,n){
        C[n/2-1][i] = val;
        o.erase(val);
        val += 2;
    }

    int k;
    for(int i = n * n - 1 ; i >= 0 ; i -= 2){
        if((i + 1) % 5 == 0){
            k = i;
            break;
        }
    }
    rep(i,n/2+1){
        C[n/2+1][i] = k - 2*i;
        e.erase(k-2*i);
    }
    val = k - 2 * (n / 2) - 10;
    // cout << val << endl;
    rrep(i,n/2+1,n){
        C[n/2][i] = val;
        e.erase(val);
        val -= 2;
    }
    rep(i,n) rep(j,n) {
        if(o.empty()) break;
        if(C[i][j] != 0) continue;
        auto it = o.begin();
        C[i][j] = *it;
        o.erase(it);
    }
    rep(i,n) rep(j,n) {
        if(e.empty()) break;
        if(C[i][j] != 0) continue;
        auto it = e.begin();
        C[i][j] = *it;
        e.erase(it);
    }
    rep(i,n){
        rep(j,n) cout << C[i][j] << " "; cout << endl;
    }
    // set<int> st;
    // rrep(i,1,n*n+1) st.insert(i);
    // rep(i,n) rep(j,n) st.erase(C[i][j]);
    // if(st.empty()) cout << "Yes" << endl;
    // else cout << "No" << endl;
    // for(int  u : st) cout << u << endl;
}