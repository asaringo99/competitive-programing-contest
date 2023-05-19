#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
ll A[202020] ;

ll f(ll x){
    ll sum = 0 ;
    rep(i,n) sum += min(A[i],x) ;
    return sum / x ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    ll lef = 0 , rig = 1e18 , res = 0 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        ll val = f(mid) ;
        if(val < k) rig = mid ;
        else lef = mid ;
    }
    cout << lef << endl ;
}