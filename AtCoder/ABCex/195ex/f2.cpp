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

struct FastPrimeFactorization{

    private :
        int n ;
        vector<int> factor ;
        vector<int> prime ;

        void build(){
            for(int i = 2 ; i <= n ; i++){
                if(factor[i] != -1) continue ;
                for(int j = i ; j <= n ; j += i) factor[j] = i ;
                prime.push_back(i) ;
            }
        }
        
    public :

        FastPrimeFactorization(int n_, bool extended = true){
            n = n_ ;
            if(extended) n = max(n_,303030) ;
            factor.resize(n+1,-1) ;
            build() ;
        }

        // 素因数分解 20 -> { (5,1), (2,2) }
        vector<P> primeFactorization(int k){
            vector<P> res ;
            while(k != 1){
                int ex = 0 ;
                int d = factor[k] ;
                while(k % d == 0){
                    k /= d ;
                    ex++ ;
                }
                res.push_back(P(d,ex)) ;
            }
            return res ;
        }

        // 素因数分解の素因数のみ 20 -> { 5, 2 }
        vector<int> primeFactor(int k){
            vector<int> res ;
            while(k != 1){
                int ex = 0 ;
                int d = factor[k] ;
                while(k % d == 0){
                    k /= d ;
                    ex++ ;
                }
                res.push_back(d) ;
            }
            return res ;
        }
        
        vector<int> getPrime() { return prime ; }
};

ll a , b ;
ll dp[75][1<<20] ;

int main(){
    cin >> a >> b ;
    FastPrimeFactorization f(b-a,false) ;
    vector<int> prime = f.getPrime() ;
    vector<ll> X ;
    int m = prime.size() ;
    for(ll x = a ; x <= b ; x++){
        ll sum = 0 ;
        rep(i,m) if(x % prime[i] == 0) sum |= 1 << i ;
        X.push_back(sum) ;
    }
    dp[0][0] = 1 ;
    int n = X.size() ;
    rep(i,n){
        rep(S,1<<m){
            if((S & X[i]) == 0) dp[i+1][S|X[i]] += dp[i][S] ;
            dp[i+1][S] += dp[i][S] ;
        }
    }
    ll res = 0 ;
    rep(S,1<<m) res += dp[n][S] ;
    cout << res << endl ;
}