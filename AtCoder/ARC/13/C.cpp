#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)

int n ;
TP X[1010] ;

int main(){
    cin >> n ;
    int res = 0 ;
    rep(i,n){
        int m ;
        int X , Y , Z ;
        cin >> X >> Y >> Z ;
        cin >> m ;
        int minx = 1e9 + 1 , miny = 1e9 + 1 , minz = 1e9 + 1 ;
        int maxx = -1 , maxy= -1 , maxz = -1 ;
        rep(j,m){
            int x , y , z ;
            cin >> x >> y >> z ;
            chmin(minx,x) ; chmax(maxx,x) ;
            chmin(miny,y) ; chmax(maxy,y) ;
            chmin(minz,z) ; chmax(maxz,z) ;
        }
        res ^= (X - 1 - maxx) ^ (Y - 1 - maxy) ^ (Z - 1 - maxz) ^ minx ^ miny ^ minz ;
    }
    if(res == 0) cout << "LOSE" << endl ;
    else cout << "WIN" << endl ;
}