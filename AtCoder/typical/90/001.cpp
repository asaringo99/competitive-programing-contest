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

int n , L , K , val ;

int A[100001] ;

bool cal(int m){
    int fr = 0 , count = 0 ;
    val = INT_MAX ;
    for(int i = 0 ; i < n + 1 ; i++){
        if(count == K){
            val = min(val,A[n]-fr) ;
            return val >= m  ;
        }
        if(A[i] - fr >= m){
            val = min(val,A[i] - fr) ;
            fr = A[i] ;
            count++ ;
        }
    }
    return false ;
}

int main(){
    cin >> n >> L >> K ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    A[n] = L ;
    ll lef = 0 , rig = L , res = INT_MAX ;
    while(rig - lef > 1){
        //cout << lef << " " << rig << endl ;
        int m = (rig + lef) / 2 ;
        bool ok = cal(m) ;
        if(ok){
            lef = m ;
            res = val ;
        }
        else rig = m ;
    }
    cout << res << endl ;
}