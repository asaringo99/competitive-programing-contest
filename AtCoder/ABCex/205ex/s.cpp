#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int H , W , n ;
P qu[101] ;
int C[101][101] ;
set<int> X[101] ;
set<int> Y[101] ;
set<P> S ;

void f(int i){
    S.erase(S.begin()) ;
    set<P> T ;
    for(int x : X[i]) for(int y : Y[i]){
        C[x][y] = true ;
        for(P it : S){
            int id = it.second ;
            if(X[id].count(x)) X[id].erase(x) ;
            if(Y[id].count(y)) Y[id].erase(y) ;
            int dx = X[id].size() , dy = Y[id].size() ;
            T.insert(P(dx*dy,id)) ;
        }
        S = T ;
        return ;
    }
}

int main(){
    cin >> H >> W >> n ;
    rep(i,n){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        a-- ; b-- ; c-- ; d-- ;
        rrep(x,a,c+1) X[i].insert(x) ;
        rrep(x,b,d+1) Y[i].insert(x) ;
        S.insert(P((d-b+1)*(c-a+1),i)) ;
    }
    while(!S.empty()){
        auto it = S.begin() ;
        P p = *it ;
        f(p.second) ;
    }
    int count = 0 ;
    rep(i,H) rep(j,W) if(C[i][j]) count++ ;
    cout << count << endl ;
}