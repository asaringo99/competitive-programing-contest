#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int r , c , k , n ;
vector<int> G[101010] ;
ll H[101010] , W[101010] ;

int main(){
    cin >> r >> c >> k >> n ;
    ll X[c] ;
    memset(X,0,sizeof(X)) ;
    rep(i,n){
        int x , y ;
        cin >> x >> y ;
        H[x]++ ;
        W[y]++ ;
        X[y-1]++ ;
        G[x].push_back(y) ;
    }
    sort(X,X+c) ;
    ll res = 0 ;
    rrep(i,1,r+1){
        ll sum = upper_bound(X,X+c,k-H[i]) - lower_bound(X,X+c,k-H[i]) ;
        for(int y : G[i]){
            ll val = H[i] + W[y] ;
            if(val == k) sum-- ;
            if(val == k + 1) sum++ ;
        }
        res += sum ;
    }
    cout << res << endl ;
}