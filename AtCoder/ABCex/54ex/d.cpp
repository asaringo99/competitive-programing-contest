#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n, ma , mb ;
TP A[50] ;

int main(){
    cin >> n >> ma >> mb ;
    rep(i,n){
        int a , b , c ;
        cin >> a >> b >> c ;
        A[i] = {a,b,c} ;
    }
    vector<P> vec ;
    int m = n / 2 ;
    int res = 1e9 ;
    rrep(S,1,1<<m){
        int a = 0 , b = 0 , c = 0 ;
        rep(i,m) if(S >> i & 1){
            int x , y , z ;
            tie(x,y,z) = A[i] ;
            a += x ; b += y ; c += z ;
        }
        if(a*mb-b*ma == 0) res = min(res,c) ;
        vec.push_back(P(a*mb-b*ma,c)) ;
    }
    sort(vec.begin(),vec.end()) ;
    n -= m ;
    rrep(S,1,1<<n){
        int a = 0 , b = 0 , c = 0 ;
        rep(i,n) if(S >> i & 1){
            int x , y , z ;
            tie(x,y,z) = A[i+m] ;
            a += x ; b += y ; c += z ;
        }
        int v = b * ma - a * mb ;
        auto it = lower_bound(vec.begin(),vec.end(),P(v,-1)) ;
        if(it == vec.end()) continue ;
        P p = *it;
        if(a*mb-b*ma == 0) res = min(res,c) ;
        if(p.first == v) res = min(res,p.second+c) ;
    }
    if(res == 1e9) res = -1 ;
    cout << res << endl ;
}