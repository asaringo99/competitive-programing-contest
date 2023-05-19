#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    P A[n] ;
    for(int i = 0 ; i < n ; i++){
        ll a , b ;
        cin >> a >> b ;
        A[i] = P(b,a) ;
    }
    sort(A,A+n) ;
    ll time = 0 ;
    bool ok = true ;
    for(int i = 0 ; i < n ; i++){
        time += A[i].second ;
        if(time > A[i].first) ok = false ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}