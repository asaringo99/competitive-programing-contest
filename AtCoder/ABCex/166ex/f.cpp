#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int,int,char> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll a , b , c ;
vector<char> vec ;
bool dp[101010][3][3][3] ;
TP pre[101010][3][3][3] ;
string X[101010] ;

int main(){
    cin >> n >> a >> b >> c ;
    if(a + b + c <= 2){
        dp[0][a][b][c] = true ;
        rep(i,n) cin >> X[i] ;
        rep(i,n) rep(x,3) rep(y,3) rep(z,3){
            if(!dp[i][x][y][z]) continue ;
            // cout << i << " " << x << " " << y << " " << z << endl ;
            if(X[i] == "AB"){
                if(x > 0){
                    dp[i+1][x-1][y+1][z] = true ;
                    pre[i+1][x-1][y+1][z] = {i,x,y,z,'B'} ;
                }
                if(y > 0){
                    dp[i+1][x+1][y-1][z] = true ;
                    pre[i+1][x+1][y-1][z] = {i,x,y,z,'A'} ;
                }
            }
            if(X[i] == "AC"){
                if(x > 0){
                    dp[i+1][x-1][y][z+1] = true ;
                    pre[i+1][x-1][y][z+1] = {i,x,y,z,'C'} ;
                }
                if(z > 0){
                    dp[i+1][x+1][y][z-1] = true ;
                    pre[i+1][x+1][y][z-1] = {i,x,y,z,'A'} ;
                }
            }
            if(X[i] == "BC"){
                if(z > 0){
                    dp[i+1][x][y+1][z-1] = true ;
                    pre[i+1][x][y+1][z-1] = {i,x,y,z,'B'} ;
                }
                if(y > 0){
                    dp[i+1][x][y-1][z+1] = true ;
                    pre[i+1][x][y-1][z+1] = {i,x,y,z,'C'} ;
                }
            }
        }
        int x = -1 , y = -1 , z = -1 ;
        rep(i,3) rep(j,3) rep(k,3) if(dp[n][i][j][k]){
            x = i ;
            y = j ;
            z = k ;
        }
        if(x == -1 && y == -1 && z == -1){
            cout << "No" << endl ;
            return 0 ;
        }
        int i = n ;
        while(i != 0){
            char c ;
            tie(i,x,y,z,c) = pre[i][x][y][z] ;
            vec.push_back(c) ;
        }
        reverse(vec.begin(),vec.end()) ;
        cout << "Yes" << endl ;
        for(char u : vec) cout << u << endl ;
        return 0 ;
    }
    rep(i,n){
        string S ;
        cin >> S ;
        if(S == "AB"){
            if(a == 0 && b == 0){
                cout << "No" << endl ;
                return 0 ;
            }
            if(a > b){
                vec.push_back('B') ;
                b++ ;
                a-- ;
            }
            else{
                vec.push_back('A') ;
                b-- ;
                a++ ;
            }
        }
        if(S == "AC"){
            if(a == 0 && c == 0){
                cout << "No" << endl ;
                return 0 ;
            }
            if(a > c){
                vec.push_back('C') ;
                c++ ;
                a-- ;
            }
            else{
                vec.push_back('A') ;
                c-- ;
                a++ ;
            }
        }
        if(S == "BC"){
            if(c == 0 && b == 0){
                cout << "No" << endl ;
                return 0 ;
            }
            if(b < c){
                vec.push_back('B') ;
                b++ ;
                c-- ;
            }
            else{
                vec.push_back('C') ;
                b-- ;
                c++ ;
            }
        }
    }
    cout << "Yes" << endl ;
    for(char u : vec) cout << u << endl ;
}