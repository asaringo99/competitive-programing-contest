#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll n ;
ll dp[61][2] ;

const int mod = 1000000007 ;

int main(){
    cin >> n ;
    vector<int> digit ;
    while(n > 0){
        if(n & 1) digit.push_back(1) ;
        else digit.push_back(0) ;
        n >>= 1 ;
    }
    reverse(digit.begin(),digit.end()) ;
    
}