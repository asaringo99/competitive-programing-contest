#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , q ;
ll A[202020] ;

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    rep(i,q){
        ll x ;
        cin >> x ;
        auto it = lower_bound(A,A+n,x) ;
        int id = it - A ;
        cout << n - id << endl ;
    }
}