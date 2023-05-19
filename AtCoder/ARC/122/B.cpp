#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
double A[100007] , S[100007] ;

double calculation(double x){
    auto it = upper_bound(A,A+n,2*x) ;
    int i = it - A ;
    return (S[n] + n * x - S[i] - (n - i) * 2 * x) / n ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    rep(i,n) S[i+1] = S[i] + A[i] ;
    int cnt = 10000 ;
    double lef = 0 , rig = 1e12 ;
    while(cnt > 0){
        double x = (lef * 2 + rig) / 3 , y = (rig * 2 + lef) / 3 ;
        if(calculation(x) < calculation(y)) rig = y ;
        else lef = x ;
        cnt-- ;
    }
    cout << setprecision(10) << calculation(rig) << endl ;
}