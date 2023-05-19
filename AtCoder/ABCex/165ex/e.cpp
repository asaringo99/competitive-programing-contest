#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;

int main(){
    cin >> n >> m ;
    int v = m ;
    rep(i,m/2+1){
        if(i + 1 == i + 1 + v) break ;
        cout << i + 1 << " " << i + 1 + v << endl ;
        v -= 2 ;
    }
    int u = m - 1 ;
    rep(i,m/2){
        cout << 2 + m + i << " " << 2 + m + i + u << endl ;
        u -= 2 ;
    }
}