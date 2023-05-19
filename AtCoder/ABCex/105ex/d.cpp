#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
unordered_map<ll,ll> mp ;

int main(){
    cin >> n >> m ;
    ll sum = 0 , res = 0 ;
    mp[0]++ ;
    rep(i,n){
        ll a ;
        cin >> a ;
        (sum += a) %= m ;
        res += mp[sum]++ ;
    }
    cout << res << endl ;
}