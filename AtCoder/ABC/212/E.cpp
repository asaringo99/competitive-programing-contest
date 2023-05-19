#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;

int n , m , k ;
vector<int> G[5007] ;
ll res[5007][5007] ;

void cal(int x){
    vector<int> A(n,0) ;
    ll sum = 0 ;
    rep(i,n) (sum += res[x][i]) %= mod ;
    rep(i,n) for(int u : G[i]) (A[u] += res[x][i]) %= mod;
    rep(i,n) res[x+1][i] = (res[x+1][i] + sum - (A[i] + res[x][i]) + 2 * mod) % mod ;
}

int main(){
    cin >> n >> m >> k ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    res[0][0] = 1;
    rep(i,k) cal(i);
    cout << res[k][0] << endl;
}