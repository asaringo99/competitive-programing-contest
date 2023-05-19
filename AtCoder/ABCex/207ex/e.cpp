#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n ;
ll A[3030] , S[3030] ;
ll dp[3030][3030] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] ;
    dp[0][0] = 1 ;

    rrep(i,1,n+1){
        unordered_map<ll,ll> mp ;
        mp[S[i-1]%i] = dp[i-1][i-1] ;
        rrep(j,i,n+1){
            (dp[i][j] += mp[S[j]%i]) %= mod ;
            (mp[S[j]%i] += dp[i-1][j]) %= mod ;
        }
    }
    ll res = 0 ;
    rrep(i,1,n+1) (res += dp[i][n]) %= mod ;
    cout << res << endl ;
}