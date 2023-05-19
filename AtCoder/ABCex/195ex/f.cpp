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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

struct Eratosthenes{
    int n ;
    vector<bool> prime ;
    vector<int> factor ;

    Eratosthenes(int n_ , bool extend = true){
        n = n_ ;
        if(extend) n = max(n,303030) ;
        prime.resize(n,true) ;
        prime[0] = prime[1] = false ;
        build() ;
    }

    void build(){
        for(int i = 2 ; i < n ; i++){
            if(!prime[i]) continue ;
            factor.push_back(i) ;
            for(int j = i * 2 ; j < n ; j += i) prime[j] = false ;
        }
    }

    bool isPrime(int k) { return prime[k] ; }
    size_t size() { return factor.size() ; }
    inline int operator [] (int i) { return factor[i] ; }
};

ll a , b ;
ll dp[80][1<<21] ;
vector<ll> A ;

int main(){
    cin >> a >> b ;
    Eratosthenes pm(72,false) ;
    int k = pm.size() ;
    rrep(i,a,b+1){
        ll sum = 0 ;
        rep(j,k){
            if(i % pm[j] == 0) sum |= 1 << j ;
        }
        A.push_back(sum) ;
    }
    int n = A.size() ;
    dp[0][0] = 1 ;
    rep(i,n){
        rep(S,1<<k) {
            if((S & A[i]) == 0) dp[i+1][S|A[i]] += dp[i][S] ;
            dp[i+1][S] += dp[i][S] ;
        }
    }
    ll res = 0 ;
    rep(i,1<<k) res += dp[n][i] ;
    cout << res << endl ;
}