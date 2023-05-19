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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename Key,typename Val>
struct hash_map{
    using u32=uint32_t;
    using u64=uint64_t;
    using Data=pair<Key,Val>;
    protected:
        template <typename K>
        inline u64 randomized(const K&key)const{
            return u64(key)^r;
        }
    template<typename K,enable_if_t<is_integral<K>::value,nullptr_t> = nullptr>
    inline u64 inner_hash(const K&key)const{
        return (randomized(key)*11995408973635179863ULL);
    }
    template<typename K,enable_if_t<is_integral<decltype(K::first)>::value,nullptr_t> = nullptr,enable_if_t<is_integral<decltype(K::second)>::value,nullptr_t> = nullptr>
        inline u64 inner_hash(const K&key)const{
            u64 a=randomized(key.first),b=randomized(key.second);
            a*=11995408973635179863ULL;
            b*=10150724397891781847ULL;
            return (a+b);
    }
    template <typename K,enable_if_t<is_integral<typename K::value_type>::value,nullptr_t> = nullptr>
    inline u64 inner_hash(const K&key)const{
        static constexpr u64 mod=(1LL << 61)-1;
        static constexpr u64 base=950699498548472943ULL;
        u64 res=0;
        for(auto&elem:key) {
            __uint128_t x=__uint128_t(res)*base+(randomized(elem)&mod);
            res=(x&mod)+(x>>61);
        }
        __uint128_t x=__uint128_t(res)*base;
        res=(x&mod)+(x >> 61);
        if(res>=mod)res-=mod;
        return (res<<3);
    }
    inline u32 hash(const Key&key)const{
        return inner_hash(key)>>shift;
    }
    void reallocate(u32 new_cap){
        vector<Data>new_data(new_cap);
        vector<bool>new_flag(new_cap,false);
        shift=64-__lg(new_cap);
        for(u32 i=0;i<cap;i++){
            if(flag[i]&&!dflag[i]){
                u32 h=hash(data[i].first);
                while(new_flag[h])h=(h+1)&(new_cap-1);
                new_data[h]=move(data[i]);
                new_flag[h]=true;
            }
        }
        data.swap(new_data);
        flag.swap(new_flag);
        cap=new_cap;
        dflag.resize(cap);
        fill(dflag.begin(),dflag.end(),false);
    }
    inline bool should_extend(u32 x)const{return x*2>=cap;}
    inline bool should_shrink(u32 x)const{return 4<cap&&x*10<=cap;}
    inline void extend(){reallocate(cap<<1);}
    inline void shrink(){reallocate(cap>>1);}
    public:
    u32 cap,s;
    vector<Data>data;
    vector<bool>flag,dflag;
    u32 shift;
    static u64 r;
    static constexpr uint32_t DEFAULT_SIZE=4;
    struct iterator{
        u32 i;
        hash_map<Key,Val>*p;
        explicit constexpr iterator():i(0),p(nullptr){}
        explicit constexpr iterator(u32 i,hash_map<Key,Val>*p):i(i),p(p){}
        explicit constexpr iterator(u32 i,const hash_map<Key,Val>*p):i(i),p(const_cast<hash_map<Key,Val>*>(p)){}
        const Data& operator*()const{
            return const_cast<hash_map<Key,Val>*>(p)->data[i];
        }
        Data& operator*(){return p->data[i];}
        Data* operator->(){return &(p->data[i]);}
        friend void swap(iterator&a,iterator&b){swap(a.i,b.i);swap(a.p,b.p);}
        friend bool operator==(const iterator&a,const iterator&b){return a.i==b.i;}
        friend bool operator!=(const iterator&a,const iterator&b){return a.i!=b.i;}
        iterator& operator++(){
        assert(i!=p->cap&&"iterator overflow");
        do{
            i++;
            if(i==p->cap)break;
            if(p->flag[i]&&!(p->dflag[i]))break;
        } while(true);
        return *this;
        } 
        iterator operator++(int){
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }
        iterator& operator--(){
            do{
                i--;
                if(p->flag[i]&&!(p->dflag[i]))break;
                assert(i!=0&&"iterator underflow");
            } while(true);
            return *this;
        }
        iterator operator--(int){
            iterator tmp(*this);
            --(*this);
            return tmp;
        }
    };
    using itr=iterator;
    explicit hash_map():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(62){}
    itr begin()const{
        u32 h=0;
        while(h!=cap){
            if(flag[h]&&!dflag[h])break;
            h++;
        }
        return itr(h,this);
    }
    itr end()const{return itr(this->cap,this);}    
    friend itr begin(hash_map<Key,Val>&a){return a.begin();}
    friend itr end(hash_map<Key,Val>&a){return a.end();}
    itr find(const Key&key)const{
        u32 h=hash(key);
        while(true){
            if(!flag[h])return this->end();
            if(data[h].first==key){
                if(dflag[h])return this->end();
                return itr(h,this);
            }
            h=(h+1)&(cap-1);
        }
    }
    bool contain(const Key&key)const{return find(key)!=this->end();}
    int count(const Key&key)const{return int(find(key)!=this->end());}
    itr insert(const Data&d){
        u32 h=hash(d.first);
        while(true){
            if(!flag[h]){
                if(should_extend(s+1)){
                    extend();
                    h=hash(d.first);
                    continue;
                }
                data[h]=d;
                flag[h]=true;
                s++;
                return itr(h,this);
            }
            if(data[h].first==d.first){
                if(dflag[h]){
                    data[h]=d;
                    dflag[h]=false;
                    s++;
                }
                return itr(h,this);
            }
            h=(h+1)&(cap-1);
        }
    }
    bool erase(itr it){
        if(it==this->end())return false;
        s--;
        if(should_shrink(s)){
            Data d=data[it.i];
            shrink();
            it=find(d.first);
        }
        int ni=(it.i+1)&(cap-1);
        if(flag[ni]){
            dflag[it.i]=true;
        }
        else{
            flag[it.i]=false;
        }
        return true;
    }
    bool erase(const Key&key){return erase(find(key));}
    bool empty()const{return s==0;}
    u32 size()const{return s;}
    void clear(){
        s=0;
        fill(flag.begin(),flag.end(),false);
        fill(dflag.begin(),dflag.end(),false);
    }
    void reserve(int n){
        if(n<=0)return;
        n=1<<(__lg(n)+2);
        if(cap<u32(n))reallocate(n);
    }
    Val& operator[](const Key&key){
        u32 h=hash(key);
        while(true){
            if(!flag[h]){
                if(should_extend(s+1)){
                    extend();
                    h=hash(key);
                    continue;
                }
                data[h]=Data(key,Val());
                flag[h]=true;
                s++;
                return data[h].second;
            }
            if(data[h].first==key){
                if(dflag[h])data[h].second=Val();
                return data[h].second;
            }
            h=(h+1)&(cap-1);
        }
    }
    bool emplace(const Key&key,const Val&val){
        return insert(Data(key,val));
    }
};
template<typename Key,typename Val>uint64_t hash_map<Key,Val>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();

const int mod = 998244353 ;

template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using modint = ModInt< mod >;

const int MAX_N = 2010101 ;

modint inv[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
modint fac[MAX_N+1] ; // (n!) (mod p) を格納

modint powmod(modint x , ll n){
    modint res = 1 ;
    while(n > 0){
        if(n & 1) res *= x;
        x *= x;
        n >>= 1 ;
    }
    return res ;
}

// 階乗の逆元(n!)^(-1)のmodを配列に格納
void f(){
    inv[0] = 1 ; inv[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        inv[i] = powmod(i,mod-2) * inv[i-1];
    }
}

// 階乗のmodを配列に格納
void g(){
    fac[0] = 1 ; fac[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        fac[i] = fac[i-1] * i;
    }
}

//nCrの計算
modint combination(ll n , ll r){
    if(n < 0 || r < 0 || n < r) return 0 ;
    return fac[n] * inv[n-r] * inv[r];
}

modint permutation(ll n , ll r){
    if(n < 0 || r < 0 || n < r) return 0 ;
    return fac[n] * inv[n-r];
}

void init(){ f() ; g() ; }

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
        vector<int> get_prime() { return prime ; }
        bool is_prime(int i) { return isprime[i] ; }
        template<typename T> vector<T> zeta_transform(vector<T> f) { return zeta_transform_(f); }
        template<typename T> vector<T> mobius_transform(vector<T> F) { return mobius_transform_(F); }
        template<typename T> vector<T> gcd_convolution(vector<T> f, vector<T> g) { return gcd_convolution_(f, g); }
};

hash_map<int,int> mp, sp, C;

void solve(){
    int n;
    cin >> n;
    vector<ll> A(2*n);
    rep(i,2*n) cin >> A[i];
    Eratosthenes ets(1010101);
    vector<bool> used(1010101,false);
    int p = 0;
    rep(i,2*n){
        if(!ets.is_prime(A[i])) {
            sp[A[i]]++;
            continue;
        }
        mp[A[i]]++;
        if(used[A[i]]) continue;
        used[A[i]] = true;
        p++;
    }
    if(p < n){
        cout << 0 << endl;
        return;
    }
    for(auto [c, s] : mp){
        C[s]++;
    }
    int m = C.size();
    vector<vector<modint>> dp(m+1,vector<modint>(p-n+1));
    dp[0][0] = fac[n];
    for(auto [c, s] : sp) dp[0][0] *= inv[s];
    int i = 0;
    for(auto [c, sum] : C){
        rep(j,p-n+1){
            rep(k,sum+1){
                if(j+k >p-n) break;
                dp[i+1][j+k] += dp[i][j] * combination(sum, k) * powmod(inv[c],k) * powmod(inv[c-1],sum-k);
            }
        }
        i++;
    }
    cout << dp[i][p-n] << endl;
}

int main(){
    fast_io
    init();
    solve();
}