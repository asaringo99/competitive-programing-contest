#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;
ll k ;
unordered_map<ll,ll> dp[20][2] ;

int main(){
    cin >> S >> k ;
    int n = S.size() ;
    vector<int> digit ;
    rep(i,n) digit.push_back(S[i] - '0') ;
    dp[1][0][digit[0]] = 1 ;
    rrep(i,1,digit[0]) dp[1][1][i] = 1 ;
    rrep(i,1,n){
        // 0
        for(auto it : dp[i][0]){
            ll num = it.first , val = it.second ;
            dp[i+1][0][num * digit[i]] = 1 ;
            rep(x,digit[i]) dp[i+1][1][x*num] += val ;
        }
        rrep(x,1,10) dp[i+1][1][x]++ ;

        // 1
        for(auto it : dp[i][1]){
            ll num = it.first , val = it.second ;
            rep(x,10) dp[i+1][1][num*x] += val ;
        }
    }
    ll res = 0 ;
    for(auto it : dp[n][0]) if(it.first <= k) res += it.second ;
    for(auto it : dp[n][1]) if(it.first <= k) res += it.second ;
    cout << res << endl ;
}