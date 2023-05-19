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

int n , m ;

P S[101010] ;
ll C[101010] ;

int main(){
    cin >> n >> m ;
    rep(i,n){
        ll s , v ;
        cin >> s >> v ;
        S[i] = P(v,s) ;
    }
    rep(i,m) cin >> C[i] ;
    sort(S,S+n) ;
    sort(C,C+m) ;
    int i = n - 1 , j = m - 1 , res = 0 ;
    while(j >= 0 && i >= 0){
        auto [v,s] = S[i] ;
        if(s <= C[j]){
            res++ ;
            j-- ;
        }
        i-- ;
    }
    cout << res << endl ;
}