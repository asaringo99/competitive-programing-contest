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
ll A[3][1010] ;

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,n) rep(j,3) cin >> A[j][i] ;
    ll res = 0 ;
    rep(S,1<<3){
        vector<ll> vec ;
        rep(i,n) {
            ll val = 0 ;
            rep(j,3){
                if(S >> j & 1) val += A[j][i] ;
                else val -= A[j][i] ;
            }
            vec.push_back(val) ;
        }
        sort(vec.begin(),vec.end(),greater<ll>()) ;
        ll sum = 0 ;
        rep(i,m) sum += vec[i] ;
        chmax(res,sum) ;
    }
    cout << res << endl ;
}