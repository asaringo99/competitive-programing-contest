#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
map<ll,ll> mp ;
map<ll,ll> user ;
set<int> B[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,1,n+1){
        int m ;
        cin >> m ;
        rep(j,m){
            int p , e ;
            cin >> p >> e ;
            int pre = mp[p] ;
            int v = user[p] ;
            if(v == 0){
                B[i].insert(p) ;
                user[p] = i ;
                mp[p] = e ;
            }
            else if(e > pre){
                if(v != -1) B[v].erase(p) ;
                B[i].insert(p) ;
                user[p] = i ;
                mp[p] = e ;
            }
            else if(e == pre){
                if(v != -1)  B[v].erase(p) ;
                user[p] = -1 ;
                mp[p] = e ;
            }
        }
    }
    int res = 0 ;
    bool ok = false ;
    rrep(i,1,n+1){
        if(B[i].empty()) ok = true ;
        else res++ ;
    }
    if(ok) res++ ;
    cout << res << endl ;
}