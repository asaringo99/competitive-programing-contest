#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll SUM = 0 , XOR = 0 , res = 0 ;
    ll lef = 0 , rig = 0 ;
    while(rig < n){
        while(rig < n && SUM + A[rig] == (XOR ^ A[rig])){
            SUM += A[rig] ;
            XOR ^= A[rig] ;
            rig++ ;
            res += rig - lef ;
        }
        while(rig < n && SUM + A[rig] != (XOR ^ A[rig])){
            SUM -= A[lef] ;
            XOR ^= A[lef] ;
            lef++ ;
        }
    }
    cout << res << endl ;
}