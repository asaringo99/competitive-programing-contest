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
map<int,int> mp ;
vector<int> vec ;
ll S[303030] ;
ll res[303030] ;

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        mp[a]++ ;
    }
    for(auto it : mp){
        vec.push_back(it.second) ;
    }
    int m = vec.size() ;
    sort(vec.begin(),vec.end()) ;
    rep(i,m) S[i+1] = S[i] + vec[i] ;
    rrep(i,1,n+1){
        auto it = upper_bound(vec.begin(),vec.end(),i) ;
        int id = it - vec.begin() ;
        ll val = S[id] + (m - id) * i ;
        res[val/i] = i ;
    }
    for(int i = n ; i > 0 ; i--) chmax(res[i],res[i+1]) ;
    rrep(i,1,n+1) cout << res[i] << endl ; 
}