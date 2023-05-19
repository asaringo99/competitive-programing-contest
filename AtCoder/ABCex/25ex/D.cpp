#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int B[2][3] , C[3][2] ;
map<vector<vector<char>>,P> dp;
map<vector<vector<char>>,bool> used;

P rec(vector<vector<char>> vec){
    if(used[vec]) return dp[vec] ;
    int count = 0 ;
    rep(i,3) rep(j,3) if(vec[i][j] == '-') count++ ;
    if(count == 0){
        int b = 0 , g = 0 ;
        rep(i,2) rep(j,3){
            if(vec[i][j] == vec[i+1][j]) b += B[i][j] ;
            if(vec[i][j] != vec[i+1][j]) g += B[i][j] ;
        }
        rep(i,3) rep(j,2){
            if(vec[i][j] == vec[i][j+1]) b += C[i][j] ;
            if(vec[i][j] != vec[i][j+1]) g += C[i][j] ;
        }
        used[vec] = true ;
        return dp[vec] = P(b,g) ;
    }
    int b = -1e8 , g = -1e8 ;
    rep(i,3) rep(j,3){
        if(vec[i][j] == '-'){
            if(count % 2 == 1){
                vec[i][j] = 'o' ;
                P p = rec(vec) ;
                int x = p.first , y = p.second ;
                if(x > b){
                    b = x ;
                    g = y ;
                }
                vec[i][j] = '-' ;
            }
            if(count % 2 == 0){
                vec[i][j] = 'x' ;
                P p = rec(vec) ;
                int x = p.first , y = p.second ;
                if(y > g){
                    b = x ;
                    g = y ;
                }
                vec[i][j] = '-' ;
            }
        }
    }
    used[vec] = true ;
    return dp[vec] = P(b,g) ;
}

int main(){
    rep(i,2) rep(j,3) cin >> B[i][j] ;
    rep(i,3) rep(j,2) cin >> C[i][j] ;
    vector<vector<char>> vec(3,vector<char>(3,'-')) ;
    P res = rec(vec) ;
    cout << res.first << endl << res.second << endl ;
}