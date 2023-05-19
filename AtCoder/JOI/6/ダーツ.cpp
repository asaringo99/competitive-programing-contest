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
vector<ll> A = {0} , B , C ;

int main(){
    cin >> n >> m ;
    rep(i,n) {
        ll a ;
        cin >> a ;
        A.push_back(a) ;
    }
    rep(i,n+1) rep(j,n+1) if(A[i]+A[j] <= m) B.push_back(A[i]+A[j]) ;
    sort(B.begin(),B.end()) ;
    ll res = 0 ;
    rep(i,n+1) rep(j,n+1){
        ll a = A[i] + A[j] ;
        if(a > m) continue ;
        auto it = upper_bound(B.begin(),B.end(),m-a) ;
        it-- ;
        chmax(res,*it+a) ;
    }
    cout << res << endl ;
}