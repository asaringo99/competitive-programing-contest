#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int H , W ;
string S[507] ;
set<int> st[1007] ;

const int mod = 998244353 ;

int main(){
    cin >> H >> W ;
    for(int i = 0 ; i < H ; i++){
        cin >> S[i] ;
    }
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            int val ;
            if(S[i][j] == '.') val = 0 ;
            if(S[i][j] == 'R') val = 1 ;
            if(S[i][j] == 'B') val = 2 ;
            st[i+j].insert(val) ;
        }
    }
    ll res = 1 ;
    for(int i = 0 ; i < H + W - 1 ; i++){
        if(st[i].count(1) == 1 && st[i].count(2) == 1) res *= 0 ;
        else if(st[i].count(0) == 1 && st[i].size() == 1){
            (res *= 2) %= mod ;
        }
    }
    cout << res << endl ;
}