#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

unordered_map<string,vector<string>> G ;
unordered_map<string,int> dp ; // わからない : 0 負け : 1 引き分け : 2 勝ち : 3
unordered_map<string,bool> used ;
string res[202020] ;

int rec(string v){
    if(dp[v] > 0) return dp[v] ;
    if(used[v]) return dp[v] = 2 ;
    used[v] = true ;
    int res = 1 , m = v.size() ;
    string tmp = "" ;
    tmp += v[m-3] ;
    tmp += v[m-2] ;
    tmp += v[m-1] ;
    if(G[tmp].size() == 0) return dp[v] = 3 ;
    res = 3 ;
    for(string u : G[tmp]){
        // cout << dp[u] << endl;
        int val = rec(u) ;
        if(val == 3){
            res = 1 ;
            break ;
        }
        // cout << dp[u] << endl ;
        // cout << dp[v] << " " << dp[u] << " " << u << " " << rec(u) << " " << used[u] << " " << val << endl ;
        if(val == 2) res = min(res,val) ;
    }
    used[v] = false ;
    return dp[v] = res ;
}

int main(){
    cin >> n ;
    rep(i,n){
        string S ;
        cin >> S ;
        int m = S.size() ;
        string s = "" ,  t = "" ;
        s += S[0] ;
        s += S[1] ;
        s += S[2] ;
        G[s].push_back(S) ;
        res[i] = S ;
    }
    rep(i,n){
        int val = rec(res[i]) ;
        if(val == 3) cout << "Takahashi" << endl ;
        if(val == 2) cout << "Draw" << endl ;
        if(val == 1) cout << "Aoki" << endl ;
    }
}