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

ll A[3] ;

int main(){
    fast_input_output
    rep(i,3) cin >> A[i] ;
    sort(A,A+3) ;
    ll y = A[2] - A[0] ;
    ll x = A[2] - A[1] ;
    A[0] -= x ;
    A[1] -= y ;
    A[2] -= x + y ;
    if(A[0] == A[1] && A[1] == A[2] && A[0] >= 0 && A[1] >= 0 && A[2] >= 0){
        cout << A[0] + x + y << endl ;
    }
    else cout << -1 << endl ;
}