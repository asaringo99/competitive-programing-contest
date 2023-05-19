#include <bits/stdc++.h>
using namespace std ;
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

int n ;
ll A[20][20] ;

inline void dfs(int v){
    if(v == 2 * n) return ;
    rrep(i,v+1,2*n){
        int a ;
        cin >> a ;
        A[v][i] = a ;
        A[i][v] = a ;
    }
    dfs(v+1) ;
}

bool used[20] ;
ll res = 0 ;
vector<ll> vec ;

inline void rec(int v){
    if(v >= 2 * n) {
        ll val = 0 ;
        for(ll u : vec) val ^= u ;
        chmax(res,val) ;
        return ;
    }
    if(used[v]){
        rec(v+1) ;
        return ;
    }
    used[v] = true ;
    rrep(i,v+1,2*n){
        if(used[i]) continue ;
        used[i] = true ;
        vec.push_back(A[v][i]) ;
        rec(v+1) ;
        used[i] = false ;
        vec.pop_back() ;
    }
    used[v] = false ;
}

int main(){
    cin >> n ;
    dfs(0) ;
    rec(0) ;
    cout << res << endl ;
}