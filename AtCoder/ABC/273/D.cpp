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

int H, W, sx, sy, n, q ;
map<int,vector<int>> mp;
map<int,vector<int>> sp;

int main(){
    fast_input_output
    cin >> H >> W >> sx >> sy >> n ;
    rep(i,n){
        int r, c;
        cin >> r >> c;
        mp[r].push_back(c);
        sp[c].push_back(r);
    }
    for(auto it: mp){
        auto[key,val] = it;
        mp[key].push_back(0);
        mp[key].push_back(W+1);
        sort(mp[key].begin(),mp[key].end());
    }
    for(auto it: sp){
        auto[key,val] = it;
        sp[key].push_back(0);
        sp[key].push_back(H+1);
        sort(sp[key].begin(),sp[key].end());
    }
    cin >> q;
    int nx = sx, ny = sy;
    rep(i,q){
        char d;
        int l;
        cin >> d >> l;
        if(d == 'L'){
            if(mp[nx].empty()){
                ny -= l;
                if(ny <= 0) ny = 1;
            }
            else{
                auto it = lower_bound(mp[nx].begin(), mp[nx].end(), ny);
                it--;
                int v = *it;
                ny -= l;
                if(v >= ny) ny = v + 1;
            }
        }
        if(d == 'R'){
            if(mp[nx].empty()){
                ny += l;
                if(ny >= W + 1) ny = W;
            }
            else{
                auto it = lower_bound(mp[nx].begin(), mp[nx].end(), ny);
                int v = *it;
                ny += l;
                if(v <= ny) ny = v - 1;
            }
        }

        if(d == 'U'){
            if(sp[ny].empty()){
                nx -= l;
                if(nx <= 0) nx = 1;
            }
            else{
                auto it = lower_bound(sp[ny].begin(), sp[ny].end(), nx);
                // for(auto it : sp[ny]) cout << it << " "; cout << endl;
                it--;
                int v = *it;
                // cout << v << endl;
                nx -= l;
                if(v >= nx) nx = v + 1;
            }
        }
        if(d == 'D'){
            if(sp[ny].empty()){
                nx += l;
                if(nx >= H + 1) nx = H;
            }
            else{
                auto it = lower_bound(sp[ny].begin(), sp[ny].end(), nx);
                int v = *it;
                nx += l;
                if(v <= nx) nx = v - 1;
            }
        }
        cout << nx << " " << ny << endl; 
    }
}