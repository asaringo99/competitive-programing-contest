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

int H, W, n, h, w;
ll A[303][303];
map<int,int> mp;
ll res[303][303];

int main(){
    fast_input_output
    cin >> H >> W >> n >> h >> w;
    rep(i,H) rep(j,W) cin >> A[i][j], mp[A[i][j]]++;
    rep(i,H){
        if(i + h > H) continue;
        map<int,int> sp = mp;
        rep(x,h) rep(y,w) {
            int val = A[i+x][y];
            sp[val]--;
            if(sp[val] == 0) sp.erase(val);
        }
        // cout << "jlk" << endl;
        // for(auto it : sp){
        //     cout << it.first << " " << it.second << endl;
        // }
        rep(j,W){
            cout << sp.size() << " ";
            if(j + w >= W) break;
            rep(x,h) {
                int val = A[i+x][j+w];
                sp[val]--;
                if(sp[val] == 0) sp.erase(val);
            }
            rep(x,h) {
                int val = A[i+x][j];
                sp[val]++;
            }
        }
        cout << endl;
    }
}