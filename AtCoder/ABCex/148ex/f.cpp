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
int T[101010] , A[101010] ;
vector<int> G[101010] ;

int t , a ;

void dfst(int v , int prev){
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        T[u] = T[v] + 1 ;
        dfst(u,v) ;
    }
}
void dfsa(int v , int prev){
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        A[u] = A[v] + 1 ;
        dfsa(u,v) ;
    }
}

int main(){
    cin >> n >> t >> a ;
    t-- ; a-- ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfsa(a,-1) ; dfst(t,-1) ;
    int res = 0 ;
    rep(i,n){
        if(T[i] < A[i]){
            res = max(res,G[i].size() == 1 ? A[i] - 1 : A[i]) ;
        }
    }
    cout << res << endl ;
}