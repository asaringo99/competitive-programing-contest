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

template<typename T = ll> struct BabyStepGiantStep{
    private:
        T x, y, p; // X ^ k ≡ Y (mod p) となる k を求める
        T m; // m := sqrt(p)
        T k;
        set<pair<T,int>> X;

        void init_(T x_, T y_, T p_) {
            x = x_;
            y = y_;
            p = p_;
            m = sqrt(p) + 1;
            k = -1;
        }

        T powmod(T x , ll n){
            T res = 1 ;
            while(n > 0){
                if(n & 1) (res *= x) %= p ;
                (x *= x) %= p ;
                n >>= 1 ;
            }
            return res ;
        }

        void build_(){
            baby_step();
            giant_step();
        }

        void baby_step(){
            T a = 1;
            for(int v = 0; v < m; v++){
                X.insert({a,v});
                a *= x;
                a %= p;
            }
        }

        void giant_step(){
            T inv = powmod(powmod(x,p-2),m);
            T v = y;
            for(int a = 0; a < m; a++){
                auto it = X.lower_bound({v,-1});
                if(it != X.end()) {
                    auto[val, b] = *it;
                    if(v == val) {
                        k = (T)a * m + b;
                        return;
                    }
                }
                v *= inv;
                v %= p;
            }
        }

    public:
        BabyStepGiantStep(){}
        BabyStepGiantStep(int x, int y, int p) { init_(x,y,p); }
        void init(int x, int y, int p) { init_(x,y,p); }
        void build() { build_(); }
        T solve() { return k; }
        T powinv(T x, T y) { return powmod(x, y); }
};

ll powmod(ll x , ll n, ll mod){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

void solve(){
    ll p, a, b, s, g;
    cin >> p >> a >> b >> s >> g;
    if(s == g){
        cout << 0 << endl;
    }
    else if(a == 0){
        if(b == g) cout << 1 << endl;
        else cout << -1 << endl;
    }
    else if(b == 0 && s == 0){
        cout << -1 << endl;
    }
    else if(b == 0 && a == 1){
        cout << -1 << endl;
    }
    else if(a == 1){
        g -= s;
        g += p;
        g %= p;
        g *= powmod(b,p-2,p);
        g %= p;
        cout << g << endl;
    }
    else{
        g *= (a - 1);
        g %= p;
        g += b;
        g %= p;
        s *= (a - 1);
        s %= p;
        s += b;
        s %= p;

        g *= powmod(s,p-2,p);
        g %= p;
        BabyStepGiantStep S(a,g,p);
        S.build();
        cout << S.solve() << endl;
    }
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}