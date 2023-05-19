#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

int n ;
P A[202020] ;
bool B[202020] ;

int main(){
    cin >> n ;
    rep(i,n) {
        int a ;
        cin >> a ;
        A[i] = P(a,i) ;
    }
    if(n == 1){
        cout << 1 << endl ;
        return 0 ;
    }
    sort(A,A+n) ;
    ll res = 1 ;
    int lef = n , rig = -1 ;
    rep(i,n){
        int id = A[i].second ;
        chmax(rig,id) ;
        chmin(lef,id) ;
        if(id == rig || id == lef) continue;
        ll sec = rig - lef + 1 ;
        ll cnt = sec - i ;
        (res *= cnt) %= mod ;
    }
    cout << res << endl ;
}