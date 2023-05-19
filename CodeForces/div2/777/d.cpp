#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

struct Eratosthenes{

    private :
        int n ;
        vector<int> factor ; // factor[i]: i を割ることのできる素数
        vector<int> prime ; // 素数
        vector<bool> isprime; // 素数判定
        vector<int> mobius; // メビウス関数

        void build(){
            for(int i = 2 ; i < n ; ++i){
                if(factor[i] != -1) continue ;
                prime.push_back(i) ;
                isprime[i] = true ;
                for(int j = i ; j < n ; j += i) {
                    factor[j] = i ;
                    if((j / i) % i == 0) mobius[j] = 0;
                    else mobius[j] = -mobius[j];
                }

            }
        }

        void init_(int n_){
            n = max(n_,101010) ;
            factor.resize(n,-1) ;
            isprime.resize(n,false) ;
            mobius.resize(n,1);
            build() ;
        }
        
        // 素因数分解 20 -> { (5,1), (2,2) }
        vector<P> prime_factorization_(int k){
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
        vector<int> prime_factor_(int k){
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
        int get_euler_phi_(int k) {
            int euler = k ;
            while(k != 1){
                int d = factor[k] ;
                while(k % d == 0) k /= d ;
                euler -= euler / d ;
            }
            return euler ;
        }

        // 高速ゼータ変換
        template<typename T> vector<T> zeta_transform_(vector<T> f){
            int n = f.size();
            for(int i = 2 ; i < n ; i++){
                if(!isprime[i]) continue;
                for(int j = (n - 1) / i ; j > 0 ; --j){
                    f[j] += f[j * i];
                }
            }
            return f;
        }

        // 高速メビウス変換
        template<typename T> vector<T> mobius_transform_(vector<T> F){
            int n = F.size();
            for(int i = 2 ; i < n ; ++i){
                if(!isprime[i]) continue;
                for(int j = 1 ; j * i < n ; ++j){
                    F[j] -= F[j * i];
                }
            }
            return F;
        }

        template<typename T> vector<T> gcd_convolution_(vector<T> f, vector<T> g){
            int n = max((int)f.size(), (int)g.size());
            vector<T> F = zeta_transform_(f);
            vector<T> G = zeta_transform_(g);
            vector<T> H(n);
            for(int i = 1 ; i < min((int)F.size(), (int)G.size()) ; ++i) H[i] = F[i] * G[i];
            return mobius_transform_(H);
        }

    public :
        Eratosthenes(){}
        Eratosthenes(int n_){ init_(n_); }
        void init(int n_) { init_(n_); }
        vector<P> prime_factorization(int k) { return prime_factorization_(k); }
        vector<int> prime_factor(int k) { return prime_factor_(k); }
        int get_euler_phi(int k) { return get_euler_phi_(k); }
        int get_mobius(int k) { return mobius[k]; }
        vector<int> get_prime() { return prime ; }
        bool is_prime(int i) { return isprime[i] ; }
        template<typename T> vector<T> zeta_transform(vector<T> f) { return zeta_transform_(f); }
        template<typename T> vector<T> mobius_transform(vector<T> F) { return mobius_transform_(F); }
        template<typename T> vector<T> gcd_convolution(vector<T> f, vector<T> g) { return gcd_convolution_(f, g); }
};

void solve(){
    ll x, d, nx, nd;
    cin >> x >> d;
    nx = x;
    nd = d;
    set<int> pr, qr;
    for(ll i = 2; i * i <= nx; i++){
        if(nx % i == 0){
            nx /= i;
            qr.insert(i);
        }
    }
    if(nx != 1) qr.insert(nx);

    for(ll i = 2; i * i <= nd; i++){
        if(nd % i == 0){
            nd /= i;
            pr.insert(i);
        }
    }
    if(nd != 1) pr.insert(nd);

    if(qr.size() == 1 && pr.size() == 1){
        int a = *qr.begin();
        int b = *pr.begin();
        if(a == b){
            
        }
    }
    
    int cnt = 0;
    while(x % d == 0){
        x /= d;
        cnt++;
    }
    if(x == 1) {
        x *= d;
        cnt--;
    }
    if(cnt <= 1){
        cout << "NO" << endl;
        return;
    }
    vector<int> q;
    for(ll i = 2; i * i <= x; i++){
        if(x % i == 0){
            x /= i;
            q.push_back(i);
        }
    }
    if(x != 1) q.push_back(x);
    // for(int u : q) cout << u << " "; cout << endl;
    if(q.size() > 1) {
        cout << "YES" << endl;
        return;
    }
    vector<int> p;
    for(ll i = 2; i * i <= d; i++){
        if(d % i == 0){
            d /= i;
            p.push_back(i);
        }
    }
    if(d != 1) p.push_back(d);
    if(cnt > 2 && p.size() > 1){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main(){
    fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve();
}