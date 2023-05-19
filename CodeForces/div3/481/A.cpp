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

int n ;
bool used[1010] ;

int main(){
    cin >> n ;
    vector<int> vec , res ;
    rep(i,n){
        int a ;
        cin >> a ;
        vec.push_back(a) ;
    }
    reverse(vec.begin(),vec.end()) ;
    rep(i,n){
        int a = vec[i] ;
        if(used[a]) continue ;
        used[a] = true ;
        res.push_back(a) ;
    }
    reverse(res.begin(),res.end()) ;
    cout << res.size() << endl ;
    for(int u : res) cout << u << " " ; cout << endl ;
}