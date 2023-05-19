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

int n , x , y ;
int A[202020] ;

int main(){
    fast_input_output
    cin >> n >> x >> y ;
    rep(i,n) cin >> A[i] ;
    bool ok = false ;
    if(x > y){
        ok = true ;
        rep(i,n){
            int mod = A[i] % (x + y) ;
            if(mod < x && mod >= y) ok = false ;
        }
    }
    else{
        rep(i,n){
            int mod = A[i] % (x + y) ;
            if(mod >= x) ok = true ;
        }
    }
    if(ok) cout << "First" << endl ;
    else cout << "Second" << endl ;
}