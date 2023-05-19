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
int n , m ;
int s , t ;
vector<int> G[303030] ;
vector<int> vec ; 
int use[303030] ;

int main(){
    fast_input_output
    cin >> s >> t >> m ;
    n = s + t ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    rrep(i,s,n){
        int a, b;
        int v = i ;
        for(int k : G[v]) use[k]++ ;
        rrep(j,i+1,n){
            int cnt = 0 ;
            int u = j ;
            for(int k : G[u]) {
                if(use[k] == 1 && cnt == 0){
                    cnt++ ;
                    a = k ;
                }
                else if(use[k] == 1 && cnt == 1){
                    cnt++ ;
                    b = k ;
                    cout << a + 1 << " " << v + 1 << " " << b + 1 << " " << u + 1 << endl ;
                    return 0 ;
                }
            }
        }
        for(int k : G[v]) use[k]-- ;
    }
    cout << -1 << endl ;
}