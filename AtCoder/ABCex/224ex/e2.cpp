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

int H , W , n ;
int C[202020] , R[202020] ;
int dp[202020] ;
P A[202020] ;
int X[202020] ;
map<int,bool> used ;
map<int,vector<int>> mp ;
int res[202020] ;

int main(){
    cin >> H >> W >> n ;
    rep(i,n){
        int l , r , a ;
        cin >> l >> r >> a ;
        l-- ; r-- ;
        A[i] = {l,r} ;
        X[i] = a ;
        mp[a].push_back(i) ;
    }
    sort(X,X+n,greater<int>()) ;
    rep(i,H) C[i] = -1 ;
    rep(i,W) R[i] = -1 ;
    rep(i,n){
        if(used[X[i]]) continue ;
        used[X[i]] = true ;
        vector<TP> vec ;
        for(int u : mp[X[i]]){
            auto [row,col] = A[u] ;
            res[u] = max(C[row],R[col]) + 1 ;
            vec.push_back({row,col,u}) ;
        }
        for(TP tp : vec){
            auto [row,col,k] = tp ;
            chmax(C[row],res[k]) ;
            chmax(R[col],res[k]) ;
        }
    }
    rep(i,n) cout << res[i] << endl ;
}