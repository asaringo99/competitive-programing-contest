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

int H , W ;
char C[101][101] ;

int main(){
    cin >> H >> W ;
    int sx , sy , gx , gy ;
    int cnt = 0 ;
    rep(i,H) rep(j,W) {
        cin >> C[i][j] ;
        if(cnt == 0 && C[i][j] == 'o') sx = i , sy = j , cnt++ ;
        if(cnt == 1 && C[i][j] == 'o') gx = i , gy = j ;
    }
    cout << abs(sx-gx) + abs(sy-gy) << endl ;
}