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
ll A[20][20] ;
char B[20][20] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) rep(j,n) cin >> B[i][j] ;
    rep(i,n) rep(j,n) A[i][j] = B[i][j] - '0' ;
    ll res = 0 ;
    rep(i,n) rep(j,n) {
        rrep(x,-1,2) rrep(y,-1,2) {
            ll sum = 0 ;
            if(x == 0 && y == 0) continue;
            int nx = i , ny = j ;
            rep(c,n){
                sum *= 10 ;
                sum += A[nx][ny] ;
                nx += x ;
                ny += y ;
                nx += n ;
                ny += n ;
                nx %= n ;
                ny %= n ;
            }
            chmax(res,sum) ;
        }
    }
    cout << res << endl;
}