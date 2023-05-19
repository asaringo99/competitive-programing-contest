#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"


vector<int> G[202020] ;

int n ;
int X[201010] ;
ll C[201010] ;
P V[202020] ;
ll A[202020] ;
bool er[202020] ;
set<int> st ;
set<P> S ;

int main(){
    fast_input_output
    cin >> n ;
    ll val = 1e18 ;
    rep(i,n) cin >> X[i] , X[i]-- , st.insert(X[i]) ;
    rep(i,n) cin >> C[i] , chmin(val,C[i]) ;
    rep(i,n){
        V[i].second = i ;
        G[i].push_back(X[i]) ;
        V[X[i]].first += C[i] ;
        A[X[i]] += C[i] ;
    }
    rep(i,n){
        S.insert(V[i]) ;
    }
    ll res = 0 ;
    while(!S.empty()){
        auto it = S.begin() ;
        auto [val,v] = *it ;
        er[v] = true ;
        res += val ;
        if(S.size() == 1) break ;
        int u = G[v][0] ;
        if(er[u]) {
            S.erase(it) ;
            continue;
        }
        auto jt = S.lower_bound(P(A[u],u)) ;
        S.erase(jt) ;
        A[u] -= C[v] ;
        S.insert(P(A[u],u)) ;
        S.erase(it) ;
    }
    cout << res << endl ;
}