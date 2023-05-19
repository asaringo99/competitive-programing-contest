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
ll A[111] , B[111] , C[222] ;
bool use[111] ;

int main(){
    cin >> n >> m ;
    rep(i,n+1) cin >> A[i] ;
    rep(i,n+m+1) cin >> C[i] ;


    rrep(i,0,n+m+1){
        ll val = 0 ;
        int count = 0 , id = -1 ;
        rep(j,m+1){
            if(i - j > n || i - j < 0) continue;
            if(use[j] || A[i-j] == 0) val += A[i-j] * B[j] ;
            else id = j ;
        }
        if(id != -1){
            B[id] = (C[i] - val) / A[i-id] ;
            use[id] = true ;
        }
    }
    rep(i,m+1) cout << B[i] << " " ; cout << endl ;
}