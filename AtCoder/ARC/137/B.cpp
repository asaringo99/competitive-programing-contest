#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int A[303030] ;
set<int> st ;

int main(){
    cin >> n ;
    int val = 0 ;
    rep(i,n) cin >> A[i] , val += A[i] ;
    int maxval = 0 , minval = 0 , maxv = 0 , minv = 0 ;
    int count = 0 ;
    rep(i,n){
        if(A[i] == 1) count++ ;
        else count-- ;
        chmax(maxval,count) ;
        chmax(maxv,maxval-count) ;
    }
    maxv = val + maxv ;
    int sum = 0 ;
    rep(i,n){
        if(A[i] == 1) sum-- ;
        else sum++ ;
        chmax(minval,sum) ;
        chmax(minv,minval-sum) ;
    }
    minv = val - minv ;
    
    cout << maxv - minv + 1 << endl ;
}