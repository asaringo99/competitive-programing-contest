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

int n , m ;
int A[30] , B[30] , C[30] ;
bool used[30] ;

vector<int> G[30] ;

ll bfs(int s){
    queue<int> que ;
    que.push(s) ;
    C[s] = 1 ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        used[v] = true ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(C[u] == C[v]) return 0 ;
            if(used[u]) continue ;
            C[u] = C[v] == 1 ? -1 : 1 ;
            que.push(u) ;
        }
    }
    return 2 ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    ll res = 0 ;
    rep(S,1<<n){
        bool ok = false ;
        rep(i,n){
            if(!(S >> i & 1)) continue ;
            for(int u : G[i]) if(S >> u & 1) ok = true ;
        }
        if(ok) continue ;
        ll sum = 1 ;
        memset(used,0,sizeof(used)) ;
        memset(C,0,sizeof(C)) ;
        rep(i,n) if(S >> i & 1) used[i] = true , C[i] = 0 ;
        rep(i,n) if(!used[i]) sum *= bfs(i) ;
        res += sum ;
    }
    cout << res << endl ;
}