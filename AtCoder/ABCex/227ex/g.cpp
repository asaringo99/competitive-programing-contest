#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

struct Eratosthenes2{
    int n ;
    vector<int> factor ;

    Eratosthenes2(int n_){
        n = max(n_,303030) ;
        factor.resize(n,-1) ;
        build() ;
    }

    void build(){
        for(int i = 2 ; i < n ; i++){
            if(factor[i] != -1) continue ;
            for(int j = i ; j < n ; j += i) factor[j] = i ;
        }
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
};

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
    vector<int> get_factor() { return factor ; }
    inline int operator [] (int i) { return factor[i] ; }
};

ll n , k ;
vector<ll> vec ;
vector<int> factor , id ;
unordered_map<ll,ll> mp ;

int main(){
    cin >> n >> k ;
    if(k == 0){
        cout << 1 << endl ;
        return 0 ;
    }
    rep(i,k) vec.push_back(n-i) ;
    sort(vec.begin(),vec.end()) ;
    factor = Eratosthenes(2000000).get_factor() ;
    Eratosthenes2 V(k+10) ;
    rrep(i,2,k+1){
        for(P p : V.primeFactorization(i)) mp[p.first] -= p.second ;
    } 

    int m  = factor.size() ;
    rep(i,m){
        ll fac = factor[i] ;
        ll x = vec[0] % fac == 0 ? 0 : fac - vec[0] % fac ;
        id.push_back(x) ;
    }
    rep(i,m){
        for(ll x = id[i] ; x < k ; x += factor[i]){
            while(vec[x] % factor[i] == 0){
                vec[x] /= factor[i] ;
                mp[factor[i]]++ ;
            }
        }
    }
    rep(i,k) {
        if(vec[i] > 1) mp[vec[i]]++ ;
    }
    ll res = 1 ;
    for(auto it : mp) (res *= (it.second + 1)) %= mod ;
    cout << res << endl ;
}