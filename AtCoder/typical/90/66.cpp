#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

double E , M ;
int L[105] , R[105] ;

int main(){
    cin >> n ;
    E = 0 ;
    M = 1 ;
    rep(i,n) cin >> L[i] >> R[i] ;
    rep(i,n-1){
        rrep(j,i+1,n){
            double pattern = (R[i] - L[i] + 1) * (R[j] - L[j] + 1) ;
            double res = 0 ;
            rrep(k,L[i],R[i]+1) rrep(m,L[j],R[j]+1) if(k > m) res++ ;
            E += res / pattern ;
        }
    }
    cout << setprecision(15) << E << endl ;
}