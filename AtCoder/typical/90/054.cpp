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

vector<int> K[101010] , L[101010] ;
bool used[101010] ;
int res[101010] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int k ;
        cin >> k ;
        rep(j,k){
            int x ;
            cin >> x ;
            x-- ;
            K[i].push_back(x) ;
            L[x].push_back(i) ;
        }
    }
    queue<int> que ;
    que.push(0) ;
    rep(i,n) res[i] = -1 ;
    res[0] = 0 ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int g : L[v]){
            if(used[g]) continue ;
            used[g] = true ;
            for(int u : K[g]){
                if(res[u] != -1) continue ;
                res[u] = res[v] + 1 ;
                que.push(u) ;
            }
        }
    }
    rep(i,n) cout << res[i] << endl ;
}