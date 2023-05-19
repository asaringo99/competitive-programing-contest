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

void solve(){
    int H, W, n;
    string S;
    cin >> H >> W;
    cin >> S;
    n = S.size();
    int rx = 0, ry = 0;
    int nx = 0, ny = 0, dx = 0, dy = 0;
    bool bx = false, by = false;
    for(char u : S){
        if(u == 'U'){
            nx--;
            if(nx < 0){
                nx = 0;
                dx++;
                rx++;
            }
            if(dx >= H){
                rx--;
                break;
            }
        }
        if(u == 'D'){
            nx++;
            if(nx > dx){
                dx++;
            }
            if(dx >= H){
                break;
            }
        }
        if(u == 'L'){
            ny--;
            if(ny < 0){
                ny = 0;
                dy++;
                ry++;
            }
            if(dy >= W){
                ry--;
                break;
            }
        }
        if(u == 'R'){
            ny++;
            if(ny > dy){
                dy++;
            }
            if(dy >= W){
                break;
            }
        }
    }
    cout << rx + 1 << " " << ry + 1 << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}