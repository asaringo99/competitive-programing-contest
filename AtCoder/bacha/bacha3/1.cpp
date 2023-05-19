#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n , k ;
ll A[101010] , B[101010] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    ll sum = 0 ;
    rep(i,n) B[i] = -1 ;
    rep(i,k){
        if(i + k > n) break ;
        B[i] = i + 1 ;
    }
    rep(i,k){
        if(i + k > n) break ;
        B[n-1-i] = i + 1 ;
    }
    rep(i,n) if(B[i] == -1) B[i] = B[i-1] ;
    rep(i,n){
        sum += A[i] * B[i] ;
    }
    cout << sum << endl ;
}