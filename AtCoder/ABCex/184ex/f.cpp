#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , t ;
ll A[101] ;
vector<ll> vec ;

int main(){
    cin >> n >> t ;
    rep(i,n) cin >> A[i] ;
    int m = n / 2 , r = n - m ;
    rep(S,1<<m){
        ll val = 0 ;
        rep(i,m) if(S >> i & 1) val += A[i] ;
        if(val > t) continue ;
        vec.push_back(val) ;
    }
    sort(vec.begin(),vec.end()) ;
    ll res = 0 ;
    rep(S,1<<r){
        ll val = 0 ;
        rep(i,r) if(S >> i & 1) val += A[m + i] ;
        if(val > t) continue ;
        auto it = upper_bound(vec.begin(),vec.end(),t-val) ; it-- ;
        res = max(res,val+*it) ;
    }
    cout << res << endl ;
}