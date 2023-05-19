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
#define alf "abcdefghijklmnopqrstuvwxyz"

const ll inf = 1LL << 60 ;

string S ;
ll K , n ;
ll dp[1010101][26] ;

int main(){
    cin >> S >> K ;
    n = S.size() ;
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 26 ; j++){
            dp[i][j] += dp[i+1][j] ;
            if(j != S[i]-'a'){
                dp[i][S[i]-'a'] += dp[i+1][j] ;
            }
            if(dp[i][S[i]-'a'] >= inf) dp[i][S[i]-'a'] = inf ;
            if(dp[i][j] >= inf) dp[i][j] = inf ;
        }
        dp[i][S[i]-'a']++ ;
    }
    string res = "" ;
    ll sum = 0 ;
    rep(i,26){
        sum += dp[0][i] ;
        if(sum >= inf) sum = inf ;
    }
    if(sum < K){
        cout << "Eel" << endl ;
        return 0 ;
    }
    rep(i,n){
        int id ;
        rep(j,26){
            id = j ;
            if(dp[i][j] >= K) break ;
            K -= dp[i][j] ;
        }
        if(K <= 0) break ;
        char c = 'a' + id ;
        res += c ;
        K-- ;
        if(K <= 0) break ;
        while(S[i] != c) i++ ;
    }
    cout << res << endl ;
}