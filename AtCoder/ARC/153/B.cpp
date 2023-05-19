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

int H, W, q;
vector<vector<char>> C;

int main(){
    fast_input_output
    cin >> H >> W;
    C.resize(H,vector<char>(W));
    rep(i,H) rep(j,W) cin >> C[i][j];
    cin >> q;
    int nowx = 0, nowy = 0;
    rep(i,q) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(nowx <= x) nowx = x - nowx;
        else nowx = H - nowx + x;
        if(nowy <= y) nowy = y - nowy;
        else nowy = W - nowy + y;
    }
    vector<int> vx;
    vector<int> vy;
    if(q & 1){
        for(int i = nowx ; i >= 0; i--) vx.push_back(i);
        for(int i = H - 1 ; i > nowx ; i--) vx.push_back(i);
        for(int i = nowy ; i >= 0; i--) vy.push_back(i);
        for(int i = W - 1 ; i > nowy ; i--) vy.push_back(i);
    }
    else{
        rep(i,nowx) vx.push_back(i+H-nowx);
        rrep(i,nowx,H) vx.push_back(i-nowx);
        rep(i,nowy) vy.push_back(i+W-nowy);
        rrep(i,nowy,W) vy.push_back(i-nowy);
    }
    // for(int i : vx) cout << i << " "; cout << endl;
    // for(int i : vy) cout << i << " "; cout << endl;
    for(int i : vx) {
        for(int j : vy){
            cout << C[i][j];
        }
        cout << endl;
    }
}