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

ll n , x , y ;

ll dfs(int lev , int type){
    if(type == 1 && lev == 1) return 1LL ;
    else if(lev == 1) return 0 ;
    if(type == 0){
        return dfs(lev-1,0) + dfs(lev,1) * x ;
    }
    else{
        return dfs(lev-1,0) + dfs(lev-1,1) * y ;
    }
}

int main(){
    fast_input_output
    cin >> n >> x >> y ;
    cout << dfs(n,0) << endl ;
}