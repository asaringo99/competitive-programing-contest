#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n ;
int A[303030] ;
vector<ll> B(40,0) ;

int main(){
    fast_input_output
    cin >> n ;
    ll res = 0 ;
    rep(i,n){
        ll a ;
        cin >> a ;
        A[i] = a ;
        rep(j,30) if(a >> j & 1) B[j]++ ;
        res += a ;
    }
    rep(i,n){
        vector<ll> C = B ;
        rep(j,30) if(A[i] >> j & 1) C[j] = n - C[j] ;
        ll sum = 0 ;
        rep(j,30) sum += (1LL << j) * C[j] ;
        chmax(res,sum) ;
    }
    cout << res << endl ;
}