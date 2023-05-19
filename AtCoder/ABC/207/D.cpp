#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<double,double> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const double pi = 3.1415926535 ;

int n ;
double A[110] , B[110] , C[110] , D[110] ;
P AB[110] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] >> B[i] ;
    rep(i,n) cin >> C[i] >> D[i] ;
    double dx = A[0] , dy = B[0] ;
    rep(i,n){
        A[i] -= dx ;
        B[i] -= dy ;
        AB[i] = P(A[i],B[i]) ;
    }
    sort(AB,AB+n) ;
    bool res = false ;
    rep(i,n){
        double mx = C[i] , my = D[i] ;
        rep(j,n){
            C[j] -= mx ;
            D[j] -= my ;
        }
        for(int j = 0 ; j < 360 ; j += 90){
            P CD[110] ;
            rep(k,n){
                double nx = C[k] * cos(pi*j/180) - D[k] * sin(pi*j/180) ;
                double ny = C[k] * sin(pi*j/180) + D[k] * cos(pi*j/180) ;
                CD[k] = P(nx,ny) ;
            }
            sort(CD,CD+n) ;
            bool ok = true ;
            rep(k,n){
                if(abs(CD[k].first - AB[k].first) > 0.1 || abs(CD[k].second - AB[k].second) > 0.0000001) ok = false ;
            }
            if(ok) res = true ;
        }
    }
    if(res) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}