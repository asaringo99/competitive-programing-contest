#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"
#define dist(a,b,ga,gb) (a - ga) * (a - ga) + (b - gb) * (b - gb)

int n ;
double AX[101010] , AY[101010] ;
double BX[101010] , BY[101010] ;

int main(){
    cin >> n ;
    double gax = 0 , gay = 0 ;
    rep(i,n){
        cin >> AX[i] >> AY[i] ;
        gax += AX[i] ;
        gay += AY[i] ;
    }
    gax /= n ;
    gay /= n ;
    double gbx = 0 , gby = 0 ;
    rep(i,n){
        cin >> BX[i] >> BY[i] ;
        gbx += BX[i] ;
        gby += BY[i] ;
    }
    gbx /= n ;
    gby /= n ;
    double ad = 0 , bd = 0 ;
    rep(i,n){
        ad += dist(AX[i],AY[i],gax,gay) ;
        bd += dist(BX[i],BY[i],gbx,gby) ;
    }
    ad = sqrt(ad) ;
    bd = sqrt(bd) ;
    cout << fixed << setprecision(15) << bd / ad << endl ;
}