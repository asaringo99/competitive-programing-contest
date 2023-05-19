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
    int n ;
    cin >> n ;
    map<int,int> mp ;
    set<int> dp1 , dp2 ;
    rep(i,n) {
        int c ;
        cin >> c ;
        mp[c]++ ;
    }
    int last = 0 ;
    for(auto it : mp){
        while(it.second > 0){
            if(dp1.count(it.first) == 1) {
                dp2.insert(it.first) ;
                it.second-- ;
                continue ;
            }
            if(dp2.count(it.first) == 1) {
                dp1.insert(it.first) ;
                it.second-- ;
                continue ;
            }
            if(dp1.size() > dp2.size()) dp2.insert(it.first) ;
            else dp1.insert(it.first) ;
            it.second-- ;
        }
        last = it.first ;
    }
    if(n % 2 == 1){
        dp1.insert(last) ;
        dp2.insert(last) ;
    }
    cout << min(dp1.size(),dp2.size()) << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}