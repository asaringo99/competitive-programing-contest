#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to ;
    ll cost ;
};

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int L ;
vector<int> digit(100,0) ;
vector<edge> G[30] ;

int main(){
    cin >> L ;
    int m = -1 ;
    rep(i,30) if(L >> i & 1){
        digit[i] = 1 ;
        m = i ;
    }
    ll v = 1 , node = 0 ;
    rep(i,m){
        G[i].push_back(edge{i+1,0}) ;
        G[i].push_back(edge{i+1,v}) ;
        v *= 2 ;
        node += 2 ;
    }
    ll sum = powll(2,m) ;
    for(int i = m - 1 ; i >= 0 ; i--){
        if(digit[i] == 1) {
            G[i].push_back(edge{m,sum}) ;
            node++ ;
            sum += powll(2,i) ;
        }
    }
    cout << m+1 << " " << node << endl ;
    rep(i,m+1) for(edge e : G[i]) cout << i + 1 << " " << e.to + 1 << " " << e.cost << endl ;
}