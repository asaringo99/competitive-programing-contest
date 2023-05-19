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

ll n , k ;
ll A[30303] , B[30303] ;

bool f(ll x){
    ll sum = 0 ;
    rep(i,n){
        auto it = upper_bound(B,B+n,x/A[i]) ;
        sum += it - B ;
    }
    return sum >= k ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    sort(B,B+n) ;
    ll lef = 0 , rig = 1e18 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}