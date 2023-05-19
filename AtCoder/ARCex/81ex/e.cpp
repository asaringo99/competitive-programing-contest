#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,char> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;
string S ;
int next_[202020][26] ;
int dp[202020] ;
P prevv[202020] ;

void f(){
    rep(i,26) next_[n][i] = n ;
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 26 ; j++) next_[i][j] = next_[i+1][j] ;
        next_[i][S[i]-'a'] = i ;
    }
}

int main(){
    fast_input_output
    cin >> S ;
    n = S.size() ;
    f() ;
    for(int i = n - 1 ; i >= 0 ; i--){
        int res = n + 1 ;
        for(int j = 0 ; j < 26 ; j++){
            int nextv = next_[i+1][j] ;
            if(res > dp[nextv] + 1){
                res = dp[nextv] + 1 ;
                prevv[i] = P(nextv,a_z[j]) ;
            }
        }
        dp[i] = res ;
    }
    string res = "" ;
    int len = n + 1 ;
    for(int i = 0 ; i < 26 ; i++){
        string tes = "" ; tes += a_z[i] ;
        int nextv = next_[0][i] ;
        if(len > dp[nextv]){
            len = dp[nextv] ;
            int v = nextv ;
            while(v != n){
                auto [u,c] = prevv[v] ;
                v = u ;
                tes += c ;
            }
            res = tes ;
        }
    }
    cout << res << endl ;
}