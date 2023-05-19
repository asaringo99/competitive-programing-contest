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

int n ;
int A[207] ;
vector<int> dpv[207][207] ;
int dp[207][207] ;

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        A[i] = a % 200 ;
    }
    memset(dp,-1,sizeof(dp)) ;
    dp[0][0] = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= 200 ; j++){
            if(dp[i][j] >= 0) {
                dp[i+1][j] = dp[i][j] ;
                dpv[i+1][j] = dpv[i][j] ;
                if(dp[i][(j + A[i]) % 200] == 1){
                    cout << "Yes" << endl ;
                    cout << dpv[i][(j + A[i]) % 200].size() << " " ;
                    for(int u : dpv[i][(j + A[i]) % 200]) cout << u << " " ;
                    cout << endl ;
                    cout << dpv[i][j].size() + 1 << " " ;
                    for(int u : dpv[i][j]) cout << u << " " ;
                    cout << i + 1 << endl ;
                    return 0 ;
                }
                dp[i+1][(j + A[i]) % 200] = 1 ;
                dpv[i+1][(j + A[i]) % 200] = dpv[i][j] ;
                dpv[i+1][(j + A[i]) % 200].push_back(i+1) ;
                
            }
        }
    }
    cout << "No" << endl ;
}