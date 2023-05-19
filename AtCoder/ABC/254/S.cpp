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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

struct FastPrimeFactorization{

    private :
        int n ;
        vector<int> factor ;
        vector<int> prime ;
        vector<bool> isprime;

        void build(){
            for(int i = 2 ; i < n ; i++){
                if(factor[i] != -1) continue ;
                for(int j = i ; j < n ; j += i) factor[j] = i ;
                prime.push_back(i) ;
                isprime[i] = true ;
            }
        }
        
    public :

        FastPrimeFactorization(int n_){
            n = max(n_,303030) ;
            factor.resize(n,-1) ;
            isprime.resize(n,false) ;
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

        // オイラーのファイ関数
        int getEulerPhi(int k) {
            int euler = k ;
            while(k != 1){
                int d = factor[k] ;
                while(k % d == 0) k /= d ;
                euler -= euler / d ;
            }
            return euler ;
        }
        
        // 素数列挙
        vector<int> getPrime() { return prime ; }
        // 素数判定
        bool isPrime(int i) { return isprime[i] ; }
};

ll n ;
vector<ll> prime ;

int main(){
    // fast_input_output
    FastPrimeFactorization fpf(202020) ;
    cin >> n ;
    if(n == 1){
        cout << 1 << endl ;
        return 0;
    }
    for(ll u : fpf.getPrime()) {
        ll s = u * u ;
        while(s <= n){
            prime.push_back(s) ;
            s *= u * u ;
        }
    }
    set<ll> st ;
    int m = prime.size() ;
    unordered_map<ll,bool> dp[m+1] ;
    dp[0][1] = true ;
    rep(i,m){
        for(auto it : dp[i]){
            auto [v,b] = it ;
            dp[i+1][v] = true ;
            st.insert(v) ;
            if(v * prime[i] <= n){
                dp[i+1][v*prime[i]] = true ;
                st.insert(v*prime[i]) ;
            }
        }
    }
    prime = {} ;
    for(ll u : st) prime.push_back(u) ;
    sort(prime.begin(),prime.end()) ;
    ll res = 0 ;
    rrep(i,1,n+1){
        ll val = 1 ;
        for(P p : fpf.primeFactorization(i)){
            auto [v,ex] = p ;
            if(ex & 1) val *= v ;
        }
        ll com = n / val ;
        auto it = upper_bound(prime.begin(),prime.end(),com) ;
        res += it - prime.begin() ; 
    }
    cout << res << endl ;
}