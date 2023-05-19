#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge
{
    int to;
    ll c;
};


int n , m , p , q , r ;
vector<edge> G[20] ;

int main(){
    cin >> n >> m >> p >> q >> r ;
    rep(i,r){
        int x , y , z ;
        cin >> x >> y >> z ;
        x-- ; y-- ;
        G[x].push_back(edge{y,z}) ;
    }
    ll res = 0 ;
    rep(S,1<<n){
        ll count = 0 ;
        vector<ll> vec(m,0) ;
        rep(i,n) if(S >> i & 1) {
            count++ ;
            for(edge u : G[i]) vec[u.to] += u.c ;
        }
        if(count == p){
            ll val = 0 ;
            sort(vec.begin(),vec.end(),greater<ll>()) ;
            rep(i,q) val += vec[i] ;
            res = max(res,val) ;
        }
    }
    cout << res << endl;
}