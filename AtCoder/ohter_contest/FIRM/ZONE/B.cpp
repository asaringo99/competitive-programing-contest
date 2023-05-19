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
int D , H ;

int main(){
    cin >> n >> D >> H ;
    int d[n] , h[n] ;
    for(int i = 0 ; i < n ; i++) cin >> d[i] >> h[i] ;
    for(int i = 0 ; i < n ; i++){
        bool ok = true ;
        double a = (double)(H - h[i]) / (double)(D - d[i]) ;
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue ;
            if(a * (double)(d[j] - D) + (double)H < h[j]) ok = false ;
        }
        if(ok){
            double ans = a * (double)(-D) + (double)H ;
            if(ans < 0) ans = 0 ;
            cout << setprecision(10) << ans << endl ;
            return 0 ;
        }
    }
}