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

int t ;

void solve(){
    int n ;
    cin >> n ;
    vector<int> A(n) ;
    rep(i,n) cin >> A[i] ;
    int res = (1 << 20) - 1 ;
    rep(i,n) if(A[i] != i) res &= A[i] ;
    cout << res << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}