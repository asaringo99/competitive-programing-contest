#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
double p[202020] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> p[i] ;
    int lef = 0 , rig = 0 ;
    double val = 0 , res = 0 ;
    while(rig < n){
        while(rig < n && rig - lef < k){
            val += (p[rig] + 1) / 2 ;
            rig++ ;
        }
        res = max(res,val) ;
        val -= (p[lef] + 1) / 2 ;
        lef++ ;
    }
    cout << setprecision(15) << res << endl ;
}