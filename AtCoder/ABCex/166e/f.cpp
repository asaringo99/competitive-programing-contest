#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,ll,ll,ll,char> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , a , b , c ;
bool dp[101010][6][6][6] ;
TP pre[101010][6][6][6] ;
string S[101010] ;

int main(){
    cin >> n >> a >> b >> c ;
    dp[0][min(a,3)][min(b,3)][min(c,3)] = true ;
    rep(i,n) cin >> S[i] ;
    rep(i,n) rep(a,5) rep(b,5) rep(c,5) if(dp[i][a][b][c]){
        if(S[i] == "AB"){
            if(a > 0) dp[i+1][a-1][b+1][c] = true , pre[i+1][a-1][b+1][c] = {i,a,b,c,'B'} ;
            if(b > 0) dp[i+1][a+1][b-1][c] = true , pre[i+1][a+1][b-1][c] = {i,a,b,c,'A'} ;
        }
        if(S[i] == "AC"){
            if(a > 0) dp[i+1][a-1][b][c+1] = true , pre[i+1][a-1][b][c+1] = {i,a,b,c,'C'} ;
            if(c > 0) dp[i+1][a+1][b][c-1] = true , pre[i+1][a+1][b][c-1] = {i,a,b,c,'A'} ;
        }
        if(S[i] == "BC"){
            if(b > 0) dp[i+1][a][b-1][c+1] = true , pre[i+1][a][b-1][c+1] = {i,a,b,c,'C'} ;
            if(c > 0) dp[i+1][a][b+1][c-1] = true , pre[i+1][a][b+1][c-1] = {i,a,b,c,'B'} ;
        }
    }
    rep(a,5) rep(b,5) rep(c,5){
        if(dp[n][a][b][c]){
            cout << "Yes" << endl ;
            vector<char> vec ;
            int i = n ;
            int x = a , y = b , z = c ;
            while(i != 0){
                char s ;
                tie(i,x,y,z,s) = pre[i][x][y][z] ;
                vec.push_back(s) ;
            }
            reverse(vec.begin(),vec.end()) ;
            for(char u : vec) cout << u << endl ;
            return 0 ;
        }
    }
    cout << "No" << endl ;
}