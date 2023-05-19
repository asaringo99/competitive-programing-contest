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

int n, m ;
ll A[202020];
int res[202020];
map<int,set<int>> mp;

int main(){
    fast_input_output
    cin >> n >> m;
    rep(i,m) cin >> A[i], A[i]--;
    rep(i,m) mp[0].insert(i);
    rep(i,m){
        int x = A[i];
        int y = A[i] + 1;
        if(mp[x].count(i)){
            mp[x].erase(i);
            swap(mp[x],mp[y]);
            mp[x].insert(i);
        }
        else if(mp[y].count(i)){
            mp[y].erase(i);
            swap(mp[x],mp[y]);
            mp[y].insert(i);
        }
        else{
            swap(mp[x],mp[y]);
        }
    }
    rep(i,n){
        for(int u : mp[i]){
            res[u] = i + 1;
        }
    }
    rep(i,m) cout << res[i] << endl;
}