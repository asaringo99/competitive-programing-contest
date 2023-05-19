#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,int> P ;
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
ll A[202020] , B[202020] ;
int dp[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) {
        int b ;
        cin >> b ;
        B[b] = i ;
    }
    rep(i,n) dp[i] = 1e9 ;
    rep(i,n){
        ll x = A[i] ;
        int j = 1 ;
        vector<P> vec ;
        while(x * j <= n){
            ll y = x * j ;
            auto it = lower_bound(dp,dp+n,B[y]) ;
            int id = it - dp ;
            vec.push_back(P(id,B[y])) ;
            j++;
        }
        for(P p : vec) chmin(dp[p.first],p.second);
    }
    int res = 0 ;
    rep(i,n) if(dp[i] != 1e9) res = i + 1;
    cout << res << endl ;
}