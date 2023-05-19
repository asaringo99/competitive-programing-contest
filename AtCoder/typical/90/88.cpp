#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
ll d[100][100] , A[100] ;
int prevv[100][100] ;
map<int,vector<P>> mp ;

void warshall_floyd(){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j] ;
                    prevv[i][j] = prevv[k][j] ;
                }
            
}

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) rep(j,n){
        d[i][j] = INT_MAX ;
        prevv[i][j] = i ;
    }
    rep(i,n) rrep(j,i,n) d[i][j] = A[j] ;
    rep(i,q){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        d[x][y] = INT_MAX ;
    }
    warshall_floyd() ;
    rep(i,n) rrep(j,i,n) {
        mp[d[i][j]].push_back(P(i,j)) ;
        if(mp[d[i][j]].size() == 2){
            P p1 = mp[d[i][j]][0] ;
            int v1 = p1.first , u1 = p1.second ;
            vector<int> vec1 ;
            for(int node = u1 ; u1 != v1 ; u1 = prevv[v1][node]) 
        }
    }

}