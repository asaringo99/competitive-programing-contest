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

ll n , x ;
ll A[2020] ;
ll V[2020][2020] ;
ll S[2020] ;

int main(){
    cin >> n >> x ;
    rep(i,n) cin >> A[i] ;
    rep(i,n){
        ll val = 1e16 ;
        V[i][i] = A[i] ;
        rrep(j,1,n){
            V[i][(i-j+n)%n] = min(V[i][(i-j+1+n)%n],A[(i-j+n)%n]) ;
        }
    }
    rep(i,n){
        ll sum = 0 ;
        rep(j,n){
            sum += V[j][(j-i+n)%n] ;
        }
        S[i] = sum ;
    }
    ll res = 1e16 ;
    rep(i,n){
        rep(j,n){
            chmin(res,S[i]+x*i) ;
        }
    }
    cout << res << endl ;
}