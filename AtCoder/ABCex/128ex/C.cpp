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

int n , m ;

int main(){
    cin >> n >> m ;
    bool S[m][n] ;
    bool P[m] ;
    memset(S,0,sizeof(S)) ;
    for(int i = 0 ; i < m ; i++){
        int k ;
        cin >> k ;
        for(int j = 0 ; j < k ; j++){
            int s ;
            cin >> s ;
            s-- ;
            S[i][s] = true ;
        }
    }
    for(int i = 0 ; i < m ; i++){
        cin >> P[i] ;
    }

    int res = 0 ;
    for(int i = 0 ; i < 1 << n ; i++){
        bool used[n] ;
        memset(used,0,sizeof(used)) ;
        for(int j = 0 ; j < n ; j++){
            if(i >> j & 1) used[j] = true ;
        }
        bool ok = true ;
        for(int j = 0 ; j < m ; j++){
            int count = 0 ;
            for(int k = 0 ; k < n ; k++){
                if(S[j][k] && used[k]) count++ ;
            }
            if(count % 2 != P[j]) ok = false ;
        }
        if(ok) res++ ;
    }
    cout << res << endl ;
}