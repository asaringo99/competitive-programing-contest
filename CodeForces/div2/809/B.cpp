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

int t;

void solve(){
    int n;
    cin >> n ;
    vector<vector<int>> C ;
    C.resize(n) ;
    rep(i,n){
        int c ;
        cin >> c ;
        c-- ;
        C[c].push_back(i) ;
    }
    rep(i,n){
        int m = C[i].size() ;
        if(m == 0){
            cout << 0 << " " ;
            continue;
        }
        int res = 1 ;
        int v = C[i][0] ;
        rrep(j,1,m){
            int u = C[i][j] ;
            if((u - v) % 2 == 1) {
                res++ ;
                v = u ;
            }
        }
        cout << res << " " ;
    }
    cout << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}