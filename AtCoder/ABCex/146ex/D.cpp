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
vector<int> G[101010] ;
int e[101010] ;
map<P,int> mp ;
int res = 0 ;

void dfs(int v , int prev , int val){
    int cnt = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        cnt++ ;
        if(val == cnt) cnt++ ;
        e[mp[P(min(v,u),max(v,u))]] = cnt ;
        dfs(u,v,cnt) ;
    }
    chmax(res,cnt) ;
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
        mp[P(a,b)] = i ;
    }
    dfs(0,-1,-1) ;
    cout << res << endl ;
    rep(i,n-1) cout << e[i] << endl ;
}