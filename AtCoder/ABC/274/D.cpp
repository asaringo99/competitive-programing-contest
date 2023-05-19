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

int n, gx, gy ;

map<int,bool> mp[1010];
map<int,bool> sp[1010];
int A[1010];


int main(){
    fast_input_output
    cin >> n >> gy >> gx ;
    rep(i,n) cin >> A[i];
    mp[0][0] = true;
    int c = 0;
    for(int i = 1 ; i < n ; i+=2){
        for(auto it : mp[c]){
            auto[t,nx] = it;
            mp[c+1][t+A[i]] = true;
            mp[c+1][t-A[i]] = true;
        }
        c++;
    }
    int k = 0;
    sp[0][A[0]] = true;
    for(int i = 2 ; i < n ; i+=2){
        for(auto it : sp[k]){
            auto[t,nx] = it;
            sp[k+1][t+A[i]] = true;
            sp[k+1][t-A[i]] = true;
        }
        k++;
    }
    if(mp[c][gx] && sp[k][gy]) cout << "Yes" << endl;
    else cout << "No" << endl;
}