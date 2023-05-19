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

int n , q ;
map<int,vector<int>> mp ;

int main(){
    cin >> n >> q ;
    rep(i,n){
        int a ;
        cin >> a ;
        mp[a].push_back(i+1) ;
    }
    rep(i,q){
        int x , k ;
        cin >> x >> k ;
        k-- ;
        if(mp[x].size() <= k) cout << -1 << endl ;
        else{
            cout << mp[x][k] << endl ;
        }
    }
}