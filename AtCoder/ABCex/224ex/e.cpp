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
P A[202020] ;
int R[202020] , C[202020] , D[202020] ;
int X[202020] , Y[202020] ;
int dph[202020] , dpw[202020] ;
int res[202020] ;

int main(){
    cin >> H >> W >> n ;
    rep(i,n){
        int r , c , d ;
        cin >> r >> c >> d ;
        r-- ; c-- ;
        R[i] = r ;
        C[i] = c ;
        D[i] = d ;
        A[i] = P(d,i) ;
    }
    sort(A,A+n,greater<P>()) ;
    int i = 0 ;
    while(i < n){
        int id = A[i].second ;
        int d = D[id] ;
        set<int> S , T ;
        while(i < n && d == D[A[i].second]){
            int j = A[i].second ;
            int r = R[j] , c = C[j] ;
            res[j] = max(dph[r],dpw[c]) ;
            chmax(X[r],res[j]+1) ;
            chmax(Y[c],res[j]+1) ;
            S.insert(r) ;
            T.insert(c) ;
            i++ ;
        }
        for(int u : S) dph[u] = X[u] ;
        for(int u : T) dpw[u] = Y[u] ;
    }
    rep(i,n) cout << res[i] << endl ;
}