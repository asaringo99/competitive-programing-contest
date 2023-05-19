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

const int mod = 998244353 ;

int n , d;
ll dp[505][1<<14];
int A[505] ;

int main(){
    fast_input_output
    cin >> n >> d ;
    rrep(i,1,n+1) cin >> A[i] ;
    dp[0][0] = 1 ;
    rrep(i,1,n+1){
        rep(S,1<<(2*d+1)){
            if(A[i] == -1) {
                int b = i - d ;
                rep(j,2*d+1){
                    if(b + j < 1) continue;
                    if(b + j > n) continue;
                    if(!(S >> j & 1)) continue;
                    int T = S ^ (1 << j) ;
                    T = T & ((1<<(2*d)) - 1) ;
                    T *= 2 ;
                    dp[i][S] += dp[i-1][T] + dp[i-1][T+1] ;
                    dp[i][S] %= mod ;
                }
            }
            else{
                if(abs(A[i] - i) > d){
                    cout << 0 << endl ;
                    return 0 ;
                }
                int b = i - d ;
                int a = A[i] - b ;
                if(!(S >> a & 1)) continue;
                int T = S ^ (1 << a) ;
                T = T & ((1<<(2*d)) - 1) ;
                T *= 2 ;
                dp[i][S] += dp[i-1][T] + dp[i-1][T+1] ;
                dp[i][S] %= mod ;
            }
        }
    }
    ll res = 0 ;
    rrep(S,1,1<<(d+1)){
        res += dp[n][S] ;
        res %= mod ;
    }
    cout << res << endl ;
}