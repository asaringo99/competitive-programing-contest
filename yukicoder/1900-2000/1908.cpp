#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
char S[1010][1010] ;
vector<int> vec[1010] ;

int main(){
    cin >> n >> m ;
    rep(i,n) rep(j,m){
        cin >> S[i][j] ;
        if(S[i][j] == 'o') vec[j].push_back(i) ;
    }
    int res = 0 ;
    rep(i,m) chmax(res,n-(int)vec[i].size()+1) ;
    cout << res << endl ;
}