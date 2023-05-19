#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
typedef int mainfunction ;
#define int long long
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , m ;

ll S[101010] , A[101010] ;
ll X[101] ;

ll dp[101010][10] ;
set<ll> st_p , st_m ;
unordered_map<int,ll> mp_p , mp_m ;

mainfunction main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,n-1) cin >> S[i] ;
    rep(i,m) cin >> X[i] ;
    A[0] = 0 ;
    rrep(i,1,n) A[i] = S[i-1] - A[i-1] ;
    rep(i,n){
        if(i % 2 == 0) st_p.insert(A[i]) , mp_p[A[i]]++ ;
        if(i % 2 == 1) st_m.insert(A[i]) , mp_m[A[i]]++ ;
    }
    ll res = 0 ;
    for(ll u : st_p){
        rep(i,m){
            ll sum = 0 ;
            ll a = X[i] - u ;
            rep(j,m){
                ll v = X[j] - a ;
                auto it = st_p.lower_bound(v) ;
                if(*it == v) sum += mp_p[v] ;
            }
            rep(j,m){
                ll v = X[j] + a ;
                auto it = st_m.lower_bound(v) ;
                if(*it == v) sum += mp_m[v] ;
            }
            chmax(res,sum) ;
        }
    }
    for(ll u : st_m){
        rep(i,m){
            ll sum = 0 ;
            ll a = X[i] - u ;
            rep(j,m){
                ll v = X[j] - a ;
                auto it = st_m.lower_bound(v) ;
                if(*it == v) sum += mp_m[v] ;
            }
            rep(j,m){
                ll v = X[j] + a ;
                auto it = st_p.lower_bound(v) ;
                if(*it == v) sum += mp_p[v] ;
            }
            chmax(res,sum) ;
        }
    }
    cout << res << endl ;

}