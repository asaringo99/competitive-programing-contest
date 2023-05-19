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

const int mod = 998244353 ;

struct FastPrimeFactorization{

    private :
        int n ;
        vector<int> factor ;
        vector<int> prime ;

        void build(){
            for(int i = 2 ; i < n ; i++){
                if(factor[i] != -1) continue ;
                for(int j = i ; j < n ; j += i) factor[j] = i ;
                prime.push_back(i) ;
            }
        }
        
    public :

        FastPrimeFactorization(int n_){
            n = max(n_,303030) ;
            factor.resize(n,-1) ;
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

ll n , k ;
unordered_map<ll,int> mp ;
vector<ll> v ;

int main(){
    fast_input_output
    cin >> n >> k ;
    FastPrimeFactorization fpf(1000001) ;
    ll m = n - k + 1 ;
    for(ll x = m ; x <= n ; x++) v.push_back(x) ;
    for(int u : fpf.getPrime()){
        ll p = m % u == 0 ? m : (m / u + 1) * u ;
        p -= m ;
        for(ll x = p ; x < k ; x += u){
            if(v[x] % u != 0) continue ;
            while(v[x] % u == 0){
                v[x] /= u ;
                mp[u]++ ;
            }
        }
    }
    for(ll u : v) mp[u]++ ;
    for(int i = 2 ; i <= k ; i++){
        for(P p : fpf.primeFactorization(i)) mp[p.first] -= p.second ;
    }
    ll res = 1 ;
    for(auto it : mp) {
        if(it.first == 1) continue ;
        (res *= (it.second + 1)) %= mod ;
    }
    cout << res << endl ;
}