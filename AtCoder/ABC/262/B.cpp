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

int n , m ;
bool C[101][101] ;

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        C[a][b] = true ;
        C[b][a] = true ;
    }
    int res = 0 ;
    rep(a,n) rrep(b,a+1,n) rrep(c,b+1,n){
        if(C[a][b] && C[b][c] && C[c][a]) res++ ;
    }
    cout << res << endl ;
}