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

int n ;
int d[505] ;

int main(){
    cin >> n ;
    ll sum = 0 ;
    rep(i,n) cin >> d[i] ;
    rep(i,n) rrep(j,i+1,n) sum += d[i] * d[j] ;
    cout << sum << endl ;
}