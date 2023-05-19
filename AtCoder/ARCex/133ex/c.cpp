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

ll H , W , k ;
ll A[202020] , B[202020] ;

int main(){
    fast_input_output
    cin >> H >> W >> k ;
    ll X = 0 , Y = 0 ;
    rep(i,H) cin >> A[i] , X += A[i] ;
    rep(i,W) cin >> B[i] , Y += B[i] ;
    if(X % k != Y % k){
        cout << -1 << endl ;
        return 0 ;
    }
    X = 0 ;
    Y = 0 ;
    rep(i,H){
        ll val = (k - 1) * W ;
        ll rem = val % k ;
        if(rem >= A[i]) X += val - (rem - A[i]) ;
        else X += val + (A[i] - rem) - k ;
    }
    rep(i,W){
        ll val = (k - 1) * H ;
        ll rem = val % k ;
        if(rem >= B[i]) Y += val - (rem - B[i]) ;
        else Y += val + (B[i] - rem) - k ;
    }
    cout << min(X,Y) << endl ;
}