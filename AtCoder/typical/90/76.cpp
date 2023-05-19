#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[100007] ;

int main(){
    cin >> n ;
    ll S = 0 ;
    rep(i,n){
        cin >> A[i] ;
        S += A[i] ;
    }
    int lef = 0 , rig = 0 ;
    ll sum = 0 ;
    bool ok = false ;
    while(lef < n){
        while(sum * 10 < S){
            sum += A[rig%n] ;
            rig++ ;
        }
        if(sum * 10 == S) ok = true ;
        while(lef < n && sum * 10 >= S){
            sum -= A[lef] ;
            lef++ ;
            if(sum * 10 == S) ok = true ;
        }
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}