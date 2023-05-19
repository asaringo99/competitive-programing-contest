#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int A[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    bool ok = false ;
    int val = 0 ;
    rep(i,n){
        if(!ok && A[i] > A[i+1]){
            ok = true ;
            val = A[i] ;
        }
    }
    rep(i,n) if(val != A[i]) cout << A[i] << " " ; cout << endl ;
}