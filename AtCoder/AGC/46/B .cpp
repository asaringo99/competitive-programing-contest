#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

using Graph = vector<vector<int>>;

vector<int> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
int main()
{
    int k,l,m,n ;
    cin >> k >> l >> n >> m ;
    int y[n][m] ;
}