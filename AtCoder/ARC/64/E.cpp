#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<double,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

struct edge
{
    double cost ;
    int to ;
};


double xs , ys , xt , yt ;
double d[1007][1007] ;
double res[1007] ;
int n ;

double dijkstra(){
    fill(res,res+1007,1e16) ;
    res[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(res[v] < p.first) continue ;
        for(int i = 0 ; i < n + 2 ; i++){
            if(v == i) continue ;
            if(res[i] > res[v] + d[v][i]){
                res[i] = res[v] + d[v][i] ;
                que.push(P(res[i],i)) ;
            }
        }
    }
    return res[n+1] ;
}

int main(){
    cin >> xs >> ys >> xt >> yt >> n ;
    double x[n+2] , y[n+2] , r[n+2] ;
    x[0] = xs ;
    y[0] = ys ;
    r[0] = 0 ;
    for(int i = 1 ; i < n + 1 ; i++) cin >> x[i] >> y[i] >> r[i] ;
    x[n+1] = xt ;
    y[n+1] = yt ;
    r[n+1] = 0 ;
    for(int i = 0 ; i < n + 2 ; i++){
        for(int j = 0 ; j < n + 2 ; j++){
            double dist = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - (r[i] + r[j]) ;
            dist = dist <= 0 ? 0 : dist ;
            d[i][j] = dist ;
        }
    }
    cout << setprecision(14) << dijkstra() << endl ;
}