#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m , r ;
ll d[202][202] ;
int R[10] ;

void warshallfloyd(){
    rep(k,n) rep(i,n) rep(j,n) chmin(d[i][j],d[i][k]+d[k][j]) ;
}

int main(){
    cin >> n >> m >> r ;
    rep(i,r) cin >> R[i] , R[i]-- ;
    sort(R,R+r) ;
    rep(i,n) rep(j,n) if(i != j) d[i][j] = 1e18 ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        d[a][b] = c ;
        d[b][a] = c ;
    }
    warshallfloyd() ;
    ll res = 1e18 ;
    do
    {
        ll tmp = 0 ;
        for(int i = 0 ; i < r - 1 ; i++){
            tmp += d[R[i]][R[i+1]] ;
        }
        res = min(tmp,res) ;
    } while (next_permutation(R,R+r));
    cout << res << endl ;
}