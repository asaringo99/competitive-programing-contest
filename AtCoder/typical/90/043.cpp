#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge
{
    P to ;
    int cost ;
};


int H , W ;
int sx , sy , gx , gy ;
char S[1007][1007] ;
int d[1007][1007] ;
map<P,vector<edge>> cost ;

int main(){
    cin >> H >> W >> sx >> sy >> gx >> gy ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    rep(i,H) rep(j,W){
        cost[P(i,j)].push_back(edge{P(i+1,j),1})
    }
}