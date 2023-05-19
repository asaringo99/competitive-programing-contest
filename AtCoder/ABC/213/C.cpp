#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int p , q , n ;
set<int> h , w ;
vector<int> H , W ;
map<int,int> ud , lr ;

int main(){
    cin >> p >> q >> n ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        H.push_back(a) ;
        W.push_back(b) ;
        h.insert(a) ;
        w.insert(b) ;
    }
    int i = 0 ;
    for(int u : h){
        i++ ;
        ud[u] = i ;
    }
    i = 0 ;
    for(int u : w){
        i++ ;
        lr[u] = i ;
    }
    rep(i,n) cout << ud[H[i]] << " " << lr[W[i]] << endl ;
}