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

template<typename T> struct Z_Algorithm{
    private:
        int n, m;
        vector<T> S, U;
        vector<int> Z, A;

        void init_(vector<T> S_, vector<T> U_){
            S = S_;
            U = U_;
            n = S.size();
            m = U.size();
            Z.resize(n,0);
            A.resize(m,0);
        }

        void build1(){
            int from = -1, last = -1;
            for(int i = 1 ; i < m ; i++){
                int now = 0;
                if(from != -1){
                    now = min(A[i-from], max(last-i,0));
                }
                while(i + now < m && U[now] == U[i+now]) now++;
                if(last < i + now){
                    last = i + now;
                    from = i;
                }
                A[i] = now;
            }
            A[0] = m;
        }

        void build2(){
            int from = -1, last = -1;
            for(int i = 0 ; i < n ; i++){
                int now = 0;
                if(from != -1){
                    now = min(A[i-from], max(last-i,0));
                }
                while(now < m && i + now < n && U[now] == S[i+now]) now++;
                if(last < i + now){
                    last = i + now;
                    from = i;
                }
                Z[i] = now;
            }
        }

        void build_(){
            build1();
            build2();
        }

    public:
        Z_Algorithm() {}
        Z_Algorithm(vector<T> S_, vector<T> U_): n(S_.size()), m(U_.size()), S(S_), U(U_) { Z.resize(n,0); A.resize(m,0); }
        void init(vector<T> S_, vector<T> U_){ init_(S_, U_); }
        void build(){ build_(); }
        vector<int> get_prefix_info(){ return Z; }
        vector<int> get_z_algorithm(){ return A; }
};

template <typename T>
struct LazySegmentTree{
    private :
        const ll linf = 1e18 ;
        const int inf = 1e8 ;
        int n , n_ ;

        vector<T> dat , lazy ;

        void build(){
            n = 1 ;
            while(n < n_) n *= 2 ;
            dat.resize(2*n-1,inf) ;
            lazy.resize(2*n-1,inf) ;
        }
        void eval(int k){
            if(lazy[k] == inf) return ;
            if(k < n - 1){
                chmin(lazy[2*k+1],lazy[k]) ;
                chmin(lazy[2*k+2],lazy[k]) ;
            }
            chmin(dat[k],lazy[k]) ;
            lazy[k] = inf ;
        }

        void update_(int a , int b , int k , int l , int r , T x){
            eval(k) ;
            if(r <= a || b <= l) return ;
            if(a <= l && r <= b) {
                chmin(lazy[k],x) ;
                eval(k) ;
                return ;
            }
            update_(a,b,2*k+1,l,(l+r)/2,x) ;
            update_(a,b,2*k+2,(l+r)/2,r,x) ;
            chmin(dat[k],min(dat[2*k+1],dat[2*k+2])) ;
        }

        void update_(int a , int b , T x){
            update_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            eval(k) ;
            if(r <= a || b <= l) return inf ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return min(lef,rig) ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n) ;
        }

    public :
        LazySegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void update(int a , int b , T x) { update_(a,b,x) ; }
};


int n, m;
string S, T;

int main(){
    cin >> S >> T;
    n = S.size();
    m = T.size();
    vector<char> A, B;
    for(char u : S) A.push_back(u);
    for(char u : T) B.push_back(u);
    Z_Algorithm<char> z(B,A);
    z.build();
    vector<int> vec = z.get_prefix_info();
    LazySegmentTree<int> dp(m+1);
    dp.update(0,1,0);
    rrep(i,1,m+1){
        int val = dp.query(i-1,i);
        int sec = vec[i-1];
        dp.update(i,i+sec,val+1);
    }
    int res = dp.query(m,m+1);
    if(res == 1e8) res = -1;
    cout << res << endl;
}