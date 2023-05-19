#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
double L[2020] , R[2020] ;

int main(){
    cin >> n ;
    rep(i,n){
        ll t , l , r ;
        cin >> t >> l >> r ;
        if(t == 1){
            L[i] = l ;
            R[i] = r ;
        }
        if(t == 2){
            L[i] = l ;
            R[i] = r - 0.1 ;
        }
        if(t == 3){
            L[i] = l + 0.1 ;
            R[i] = r ;
        }
        if(t == 4){
            L[i] = l + 0.1 ;
            R[i] = r - 0.1 ;
        }
    }
    ll res = 0 ;
    rep(i,n){
        rrep(j,i+1,n){
            double lef = max(L[i],L[j]) ;
            double rig = min(R[i],R[j]) ;
            if(rig - lef < 0) continue ;
            res++ ;
        }
    }
    cout << res << endl ;
}