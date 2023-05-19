#include <bits/stdc++.h>
using namespace std ;
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

int n , k ;
ll A[202020] , S[202020] ;
unordered_map<ll,ll> mp ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) S[i+1] = (S[i] + A[i]) % k ;
    rep(i,n+1) S[i] = ((S[i] - i) % k + k) % k ;
    ll res = 0 ;
    mp[0] = 1 ;
    rrep(i,1,n+1){
        if(i >= k) mp[S[i-k]]-- ;
        res += mp[S[i]] ;
        mp[S[i]]++ ;
    }
    cout << res << endl ;
}