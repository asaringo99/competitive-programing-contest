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

ll n ;
int L[2020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> L[i] ;
    sort(L,L+n) ;
    ll res = n * (n - 1) * (n - 2) / 6 ;
    rep(i,n) rrep(j,i+1,n){
        auto it = lower_bound(L,L+n,L[i]+L[j]) ;
        int cnt = it - L ;
        cnt = n - cnt ;
        res -= cnt ;
    }
    cout << res << endl ;
}