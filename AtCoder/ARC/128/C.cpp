#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ; 
double m , s ;

double A[5050] ;

int main(){
    cin >> n >> m >> s ;
    rep(i,n) cin >> A[i] ;
    reverse(A,A+n) ;

    double res = 0 ;
    bool ok = true ;
    rrep(p,1,n+1){
        double q = min(s / p , m) ;
        double sum = 0 ;
        rep(i,p) sum += q * A[i] ;
        double rem = s - q * p ;
        double val = 0 ;
        rrep(i,p,n){
            val += A[i] ;
            double tmp = min(m,rem/(i-p+1)) ;
            res = max(res,sum+tmp*val) ;
        }
        res = max(res,sum) ;
    }
    cout << fixed << setprecision(10) << res << endl ;
}