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

int t ;

int main(){
    cin >> t ;
    rep(zz,t){
        int n ;
        string S ;
        cin >> n >> S ;
        int k = (n + 1) / 2 ;
        vector<vector<ll>> dp(n+20,vector<ll>(2,0)) ;
        dp[0][0] = 1 ;
        rep(i,k){
            (dp[i+1][1] = dp[i][1] * 26) %= mod ;
            (dp[i+1][1] += (S[i] - 'A')) %= mod ;
        }
        int i , j ;
        if(n % 2 == 0){
            i = k - 1 ;
            j = k ;
        }
        else{
            i = k - 1 ;
            j = k - 1 ;
        }
        // cout << i << " " << j << endl ;
        bool ok = true ;
        int y = k ;
        while(i >= 0 && j < n){
            // if(zz == 4) cout << S[i] - 'A' << " " << S[j] - 'A' << endl ;
            if(S[i] == S[j]) {
                i-- ;
                j++ ;
                continue ;
            }
            if(S[i]-'A' > S[j]-'A'){
                ok = false ;
                break ;
            }
            break ;
        }
        ll res = dp[k][1] ;
        if(ok) res++ ;
        res %= mod ;
        cout << res << endl ;
    }
}