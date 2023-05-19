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
P A[101010] ;

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m) cin >> A[i].second >> A[i].first ;
    ll res = 0 ;
    sort(A,A+m) ;
    int end = -1 ;
    rep(i,m){
        auto[t,s] = A[i] ;
        if(s >= end){
            res++ ;
            end = t ;
        }
    }
    cout << (n - 1) * 2 - res << endl ;
}