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

int n ;
int A[202020];
vector<int> vec[202020];
bool used[202020];

int main(){
    // fast_input_output
    cin >> n ;
    rrep(i,1,n+1) cin >> A[i];
    FastPrimeFactorization fpf(n+10);
    vector<int> prime = fpf.getPrime();
    ll res = 0;
    rrep(x,2,n+1){
        if(!fpf.isPrime(x)) continue;
        vector<int> vec ;
        for(int i = x ; i <= n ; i += x) {
            vec.push_back(A[i]);
        }
        int m = vec.size();
        unordered_map<int,ll> mp;
        for(int u : vec){
            vector<int> fct = fpf.primeFactor(u);
            ll c = 0;
            for(int v : fct) chmax(c,mp[v]++);
            res += c;
        }
        cout << res << endl;
    }
    rrep(i,2,n+1) if(A[i] != 1) res++;
    cout << res << endl;
}