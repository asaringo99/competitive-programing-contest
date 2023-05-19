#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
int S[101] ;
TP X[101] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int s , d , c ;
        cin >> s >> d >> c ;
        s-- ; d-- ;
        X[i] = {d,s,c,i} ;
    }
    sort(X,X+m) ;
    rep(i,m){
        int d , s , c , id ;
        tie(d,s,c,id) = X[i] ;
        S[d] = m + 1 ;
        rrep(j,s,d){
            if(S[j] != 0) continue ;
            S[j] = id + 1 ;
            c-- ;
            if(c == 0) break ;
        }
        if(c != 0){
            cout << -1 << endl ;
            return 0 ;
        }
    }
    rep(i,n) cout << S[i] << " " ; cout << endl ;
}