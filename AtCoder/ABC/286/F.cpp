#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define all(a) a.begin(), a.end()
#define endl "\n"

struct Eratosthenes{

    private :
        int n ;
        vector<int> factor ; // factor[i]: i を割ることのできる素数
        vector<ll> prime ; // 素数
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
            n = max(n_,303030) ;
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
        vector<ll> get_prime() { return prime ; }
        bool is_prime(int i) { return isprime[i] ; }
        template<typename T> vector<T> zeta_transform(vector<T> f) { return zeta_transform_(f); }
        template<typename T> vector<T> mobius_transform(vector<T> F) { return mobius_transform_(F); }
        template<typename T> vector<T> gcd_convolution(vector<T> f, vector<T> g) { return gcd_convolution_(f, g); }
};

struct Numeric{

    tuple<ll,ll,ll> ext_gcd(ll a, ll b){
        if(b == 0) return {a, 1, 0};
        auto[g, x, y] = ext_gcd(b, a % b);
        ll q = a / b;
        ll nx = y;
        ll ny = x - q * nx;
        return {g, nx, ny};
    }

    // ax + by = r の解
    // x = k + ct, y = m + dt を求める => { gcd(), k, c, m, d } を出力する
    tuple<ll,ll,ll,ll,ll> indetermin_equation(ll a, ll b, ll r){
        auto[g, x, y] = ext_gcd(a,b);
        if(r % g != 0) return {-1,-1,-1,-1,-1};
        ll v = r / g;
        ll c = b / g;
        ll d = a / g;
        return {g,x*v,c*v,y*v,-d*v};
    }

    ll mod_inv(ll a, ll mod){
        auto[g, x, y] = ext_gcd(a, mod);
        if(g != 1) return -1;
        x += mod;
        x %= mod;
        return x;
    }

    // Mの要素は互いに素である必要がある, 互いに素でない場合 -1 を出力する O(NlogN)
    ll garner(vector<ll> A, vector<ll> M){
        assert(A.size() == M.size());
        int n = A.size();
        ll m = 1;
        ll x = A[0] % M[0];
        for(int i = 1; i < n; i++){
            m *= M[i-1];
            ll inv = mod_inv(m, M[i]);
            if(inv == -1) return -1;
            ll t = (A[i] - x) * inv % M[i];
            if(t < 0) t += M[i];
            x += t * m;
        }
        return x;
    }

    // 任意modに対するgarner O(N^2)
    // Mの要素は互いに素である必要がある, 互いに素でない場合 -1 を出力する
    // S[k]: 累積積をM[k]で割ったあまり
    // C[k]: 以下参照
    // t[k]: k-1番目までで得られた解xに対して x:= x + S[k-1] * t かつ x = A[k] (mod M[k]) となれば連立合同式を保てる。この時のtがt[k]
    // S[k] = (M[k-1]M[k-2]...M[1]) % M[k]
    // C[k] = (t[0] + t[1]M[0] + t[2]M[0]M[1] + ... + t[k-1]M[0]M[1]...M[k-2]) % M[k]
    //      = (t[0] + t[1]S[0] + t[2]S[1] + ... + t[k-1]S[k-2]) % M[k]
    ll garner(vector<ll> A, vector<ll> M, ll mod){
        M.push_back(mod);
        vector<ll> S((int)M.size(), 1);
        vector<ll> C((int)M.size(), 0);
        for(int k = 0; k < (int)A.size(); k++){
            ll inv = mod_inv(S[k], M[k]);
            if(inv == -1) return -1;
            ll t = (A[k] - C[k]) * inv % M[k];
            if(t < 0) t += M[k];
            for(int i = k + 1; i < (int)M.size(); i++){
                (C[i] += t * S[i]) %= M[i];
                (S[i] *= M[k]) %= M[i];
            }
        }
        return C[C.size()-1];
    }
};

int n;

int main(){
    // fast_io
    Eratosthenes ets(101010);
    vector<ll> prime = ets.get_prime();
    
    ll val = 25;
    int t = 4;
    vector<ll> pprime = {4,5,7,9};
    rrep(i,4,100){
        if(val + prime[i] <= 110){
            pprime.push_back(prime[i]);
            val += prime[i];
            t++;
        }
        else break;
    }
    ll now = 0;
    vector<ll> inp;
    rep(i,pprime.size()){
        rep(j,pprime[i]-1){
            inp.push_back(inp.size()+2);
        }
        inp.push_back(now+1);
        now += pprime[i];
    }
    cout << inp.size() << endl;
    rep(i,inp.size()){
        if(i == inp.size() - 1) cout << inp[i] << endl;
        else cout << inp[i] << " ";
    }
    vector<ll> A(inp.size());
    rep(i,inp.size()) cin >> A[i];
    now = 0;
    vector<ll> M, Q;
    rep(i,t){
        int con = now, pos = -1;
        rep(j,pprime[i]){
            if(inp[now] == A[now+j]){
                pos = now + j;
                M.push_back((pprime[i]-j)%pprime[i]);
                Q.push_back(pprime[i]);
                break;
            }
        }
        now += pprime[i];
    }
    Numeric numeric;
    ll ans = numeric.garner(M, Q);
    cout << ans + 1 << endl;
    // cout << M.size() << " " << Q.size() << endl;
    // rep(i,Q.size()) cout << M[i] << " " << Q[i] << endl;
}