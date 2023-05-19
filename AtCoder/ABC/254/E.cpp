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

int n , m , q ;

vector<int> G[202020] ;
bool used[202020] ;
set<ll> st ;

ll dfs(int v , int prev , int k){
    if(k == 0) return v + 1 ;
    ll res = v + 1 ;
    for(int u : G[v]){
        if(u == prev) continue;
        if(used[u]) continue;
        used[u] = true ;
        res += dfs(u,v,k-1) ;
    }
    return res ;
}

void ddfs(int v , int prev , int k){
    st.insert(v+1) ;
    if(k == 0) return ;
    for(int u : G[v]){
        if(u == prev) continue;
        ddfs(u,v,k-1) ;
    }
    return ;
}

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    cin >> q ;
    rep(i,q){
        int x , k ;
        cin >> x >> k ;
        st = {} ;
        x-- ;
        // cout << dfs(x,-1,k) << endl ;
        ddfs(x,-1,k) ;
        ll res = 0 ;
        for(ll u : st) res += u ;
        cout << res << endl ;
    }
}