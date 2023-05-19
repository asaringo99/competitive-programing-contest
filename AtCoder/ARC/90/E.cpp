#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
vector<int> G[101010] ;



int main(){
    cin >> n >> m ;
    rep(i,m){
        int v , u ;
        cin >> v >> u ;
        v-- ; u-- ;
        G[v].push_back(u) ;
        G[u].push_back(v) ;
    }
}