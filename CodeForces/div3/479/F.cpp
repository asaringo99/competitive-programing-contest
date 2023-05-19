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
map<ll,int> dp ;
ll A[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    int res = 0 ;
    int val = -1 ;
    rep(i,n){
        dp[A[i]] = dp[A[i]-1] + 1 ;
        if(res < dp[A[i]]){
            res = dp[A[i]] ;
            val = A[i] ;
        }
    }
    int s = val - res + 1 ;
    vector<int> vec ;
    rep(i,n){
        if(A[i] == s){
            vec.push_back(i+1) ;
            s++ ;
        }
    }
    cout << vec.size() << endl ;
    for(int u : vec) cout << u << " " ; cout << endl ;
}