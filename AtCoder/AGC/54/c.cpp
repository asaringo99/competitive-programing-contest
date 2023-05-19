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

const int mod = 998244353 ;

int n , k ;
int A[5050] , M[5050] , C[5050] ;

int main(){
    cin >> n >> k ;
    rep(i,n){
        int a ;
        cin >> a ;
        A[i] = a ;
        M[a] = i ;
    }
    rep(i,n){
        int count = 0 ;
        rep(j,i) if(A[j] > A[i]) count++ ;
        C[i] = count ;
    }
    ll res = 1 ;
    int lef = 0 ;
    rrep(i,1,n+1){
        int id = M[i] ;
        if(id < lef) continue ;
        if(C[id] != k) continue;
        lef = id ;
        (res *= (n - id)) %= mod ;
    }
    cout << res << endl ;
}