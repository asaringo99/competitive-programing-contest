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

const int mod = 1000000007 ;

int n ;
ll D[101010] ;
ll A1[101010] , S1[101010] ;
ll A2[101010] , S2[101010] ;
ll A3[101010] , S3[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> D[i] ;
    sort(D,D+n) ;
    rep(i,n){
        auto it = lower_bound(D,D+n,D[i]*2) ;
        int id = it - D ;
        A3[i] = n - id ;
    }
    rep(i,n) S3[i+1] = (S3[i] + A3[i]) % mod ;
    rep(i,n){
        auto it = lower_bound(D,D+n,D[i]*2) ;
        int id = it - D ;
        A2[i] = (S3[n] - S3[id] + mod) % mod ;
    }
    rep(i,n) S2[i+1] = (S2[i] + A2[i]) % mod ;
    rep(i,n){
        auto it = lower_bound(D,D+n,D[i]*2) ;
        int id = it - D ;
        A1[i] = (S2[n] - S2[id] + mod) % mod ;
    }
    rep(i,n) S1[i+1] = (S1[i] + A1[i]) % mod ;
    cout << S1[n] << endl ;
}