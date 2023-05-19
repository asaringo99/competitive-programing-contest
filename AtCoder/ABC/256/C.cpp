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

int H[10] , W[10] ;
int A[10][10] ;

int main(){
    fast_input_output
    int x = -1 ;
    rep(i,3) cin >> H[i] , chmax(x,H[i]) ;
    rep(i,3) cin >> W[i] , chmax(x,W[i]) ;
    int res = 0 ;
    rrep(i,1,x) rrep(j,1,x){
        rrep(k,1,x) rrep(l,1,x){
            A[0][0] = i ;
            A[0][1] = j ;
            A[1][0] = k ;
            A[1][1] = l ;
            A[0][2] = H[0] - i - j ;
            A[1][2] = H[1] - k - l ;
            A[2][0] = W[0] - i - k ;
            A[2][1] = W[1] - j - l ;
            if(A[0][2] <= 0 || A[1][2] <= 0 || A[2][0] <= 0 || A[2][1] <= 0) continue;
            if(W[2] - A[0][2] - A[1][2] != H[2] - A[2][0] - A[2][1]) continue;
            if(W[2] - A[0][2] - A[1][2] <= 0) continue;
            res++ ;
        }
    }
    cout << res << endl ;
}