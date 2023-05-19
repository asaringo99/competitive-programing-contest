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

int n ;
int A[202020] , B[202020] ;
vector<int> G[202020] ;
int dep ;

int dfs(int v , int prev , int x){
    int res = 0 ;
    for(int u : G[v]){
        if(u == prev) continue;
        res += dfs(u,v,x) ;
    }
    if(res > 0) res-- ;
    if(A[v] >= x) res++ ;
    return res ;
}

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,1,n) cin >> A[i] , B[i] = A[i] ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    sort(B,B+n) ;
    int lef = 0 , rig = n ;
    while(rig - lef > 1){
        int mid = (lef + rig) / 2 ;
        if(dfs(0,-1,B[mid]) > 0) lef = mid ;
        else rig = mid ;
    }
    cout << B[lef] << endl ;
}