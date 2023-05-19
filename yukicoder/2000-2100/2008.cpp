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

const int mod = 1000000007 ;

int n ;
ll A[202020] , B[202020] ;
vector<TP> X , Y ;

int main(){
    fast_input_output
    cin >> n ;
    ll sum = 0 ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rep(i,n){
        if(A[i] < B[i]) X.push_back({A[i]*B[i],-A[i],B[i]}) ;
        else Y.push_back({A[i]*B[i],-A[i],B[i]}) ;
    }
    sort(X.begin(),X.end()) ;
    sort(Y.begin(),Y.end(),greater<TP>()) ;
    ll res = 0 , k = 1 ;
    for(auto x : X){
        auto[v,a,b] = x ;
        a = -a ;
        res += k * a % mod ;
        res %= mod ;
        k *= b ;
    }
    for(auto x : Y){
        auto[v,a,b] = x ;
        a = -a ;
        res += k * a % mod ;
        res %= mod ;
        k *= b ;
    }
    cout << res << endl ;
}