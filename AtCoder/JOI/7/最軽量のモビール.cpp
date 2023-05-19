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

struct edge{
    int lef, rig ;
};

int n ;
edge G[101] ;
edge W[101] ;
int A[101] , B[101] ;

ll dfs(int v) {
    ll g = gcd(A[v],B[v]) ;
    ll aw = B[v] / g , bw = A[v] / g ;
    if(G[v].lef == -1 && G[v].rig == -1){
        return aw + bw ;
    }
    else if(G[v].lef == -1){
        ll rw = dfs(G[v].rig) , lw = 1 ;
        rw = lcm(rw,bw) ;
        lw = aw * rw / bw ;
        return lw + rw ;
    }
    else if(G[v].rig == -1){
        ll rw = 1 , lw = dfs(G[v].lef) ;
        lw = lcm(lw,aw) ;
        rw = bw * lw / aw ;
        return lw + rw ;
    }
    else{
        ll rw = dfs(G[v].rig) , lw = dfs(G[v].lef) ;
        lw = lcm(lw,aw) ;
        rw = lcm(rw,bw) ;
        ll nrw = lcm(lw * bw / aw , rw) , nlw = nrw * aw / bw ;
        ll mlw = lcm(rw * aw / bw , lw) , mrw = mlw * bw / aw ;
        return min(nrw+nlw,mrw+mlw) ;
    }
}

int main(){
    cin >> n ;
    set<int> st ;
    rep(i,n) st.insert(i) ;
    rep(i,n){
        int p , q , r , b ;
        cin >> p >> q >> r >> b ;
        A[i] = p ;
        B[i] = q ;
        G[i].lef = r - 1 ;
        G[i].rig = b - 1 ;
        if(st.count(r-1) == 1) st.erase(r-1) ;
        if(st.count(b-1) == 1) st.erase(b-1) ;
    }
    auto it = st.begin() ;
    cout << dfs(*it) << endl ;
}