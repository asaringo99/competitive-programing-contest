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

int t ;

void solve(){
    int n , m ;
    cin >> n >> m ;
    vector<int> A(n) ;
    rep(i,n) {
        int a ;
        cin >> a ;
        A[i] = min(a,m+1-a) - 1 ;
    }
    string B = "" ;
    rep(i,m) B += 'B' ;
    rep(i,n){
        int a = A[i] ;
        if(B[a] == 'B') B[a] = 'A' ;
        else B[m-1-a] = 'A' ;
    }
    for(char u : B) cout << u ; cout << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}