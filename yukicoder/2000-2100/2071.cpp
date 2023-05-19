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
int A[202020];
bool dp[18][1 << 18] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    if(n > 16) {
        cout << (1LL << 16) - 1 << endl;
        return 0;
    }
    dp[0][0] = true;
    rep(i,n){
        int a = A[i];
        rep(S,1<<16){
            if(!dp[i][S]) continue;
            rep(j,20){
                dp[i+1][S | a] = true;
                if(a & 1){
                    a /= 2;
                    a += (1 << 15);
                }
                else{
                    a /= 2;
                }
            }
        }
    }
    int res = 0;
    rep(S,1<<17) if(dp[n][S]) res = S;
    cout << res << endl;
}