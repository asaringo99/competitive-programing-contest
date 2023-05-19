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

ll n , c ;
ll T[202020] , A[202020] ;
ll mp_0[202020][33] ;
ll mp_1[202020][33] ;

int main(){
    fast_input_output
    cin >> n >> c ;
    rep(i,n) cin >> T[i] >> A[i] ;
    ll x = 0 ;
    rep(i,n){
        if(T[i] == 1){
            x = x & A[i] ;
        }
        if(T[i] == 2){
            x = x | A[i] ;
        }
        if(T[i] == 3){
            x = (x ^ A[i]) ;
        }
        rep(d,30) if(x >> d & 1) mp_0[i][d] = 1 ;
    }
    x = (1 << 30) - 1 ;
    rep(i,n){
        if(T[i] == 1){
            x = x & A[i] ;
        }
        if(T[i] == 2){
            x = x | A[i] ;
        }
        if(T[i] == 3){
            x = (x ^ A[i]) ;
        }
        rep(d,30) if(x >> d & 1) mp_1[i][d] = 1 ;
    }
    rep(i,n){
        ll res = 0 ;
        rep(d,30) {
            if(c >> d & 1) {
                if(mp_1[i][d] == 1) res += 1 << d ;
            }
            else {
                if(mp_0[i][d] == 1) res += 1 << d ;
            }
        }
        cout << res << endl ;
        c = res ;
    }
}