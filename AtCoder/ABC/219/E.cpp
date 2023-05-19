#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m , q ;
P S[202020] , T[202020] ;

vector<int> G[202020] , F[202020] ;

int main(){
    cin >> n >> m >> q ;
    rep(i,m) {
        int u , v ;
        cin >> u >> v ;
        u-- ;
        v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }

    int sqrtN = sqrt(2*n) ;
    rep(v,n){
        if(G[v].size() >= sqrtN){
            for(int u : G[v]) F[u].push_back(v) ;
        }
    }

    rep(i,n) S[i] = P(0,i) ;
    rrep(i,1,q+1){
        int x ;
        cin >> x ;
        x-- ;

        int &p = S[x].first ; 
        int &q = S[x].second ;
        for(int u : F[x]){
            int a = T[u].first , b = T[u].second ;
            if(a > p){
                p = a ;
                q = b ;
            }
        }

        if(G[x].size() >= sqrtN) T[x] = P(i,q) ;
        else for(int u : G[x]) S[u] = P(i,q) ;
    }

    rep(v,n){
        int p = S[v].first , q = S[v].second ;
        for(int u : F[v]){
            int a = T[u].first , b = T[u].second ;
            if(a > p){
                p = a ;
                q = b ;
            }
        }
        cout << q + 1 << " " ;
    }
    cout << endl ;
}