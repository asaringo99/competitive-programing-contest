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

const int mod = 1000000007 ;

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

template<int mod, int primitive_root> struct NTT {
public:
	int get_mod() const { return mod; }
	void _ntt(vector<ll>& a, int sign) {
		const int n = (int)a.size();
		assert((n ^ (n&-n)) == 0); //n = 2^k

		const int g = 3; //g is primitive root of mod
		int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
		if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod

		//bit reverse
		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}

		for (int m = 1; m < n; m *= 2) {
			const int m2 = 2 * m;
			const ll base = mod_pow(h, n / m2, mod);
			ll w = 1;
			rep(x, m) {
				for (int s = x; s < n; s += m2) {
					ll u = a[s];
					ll d = a[s + m] * w % mod;
					a[s] = u + d;
					if (a[s] >= mod) a[s] -= mod;
					a[s + m] = u - d;
					if (a[s + m] < 0) a[s + m] += mod;
				}
				w = w * base % mod;
			}
		}

		for (auto& x : a) if (x < 0) x += mod;
	}
	void ntt(vector<ll>& input) {
		_ntt(input, 1);
	}
	void intt(vector<ll>& input) {
		_ntt(input, -1);
		const int n_inv = mod_inv((int)input.size(), mod);
		for (auto& x : input) x = x * n_inv % mod;
	}

	// 畳み込み演算を行う
	vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
		int ntt_size = 1;
		while (ntt_size < (int)a.size() + (int)b.size()) ntt_size *= 2;

		vector<ll> _a = a, _b = b;
		_a.resize(ntt_size); _b.resize(ntt_size);

		ntt(_a);
		ntt(_b);

		rep(i, ntt_size){
			(_a[i] *= _b[i]) %= mod;
		}

		intt(_a);
		return _a;
	}
};

struct ArbitaryModConvolution{

    ll garner(vector<P> mr, int mod){
        mr.emplace_back(mod, 0);

        vector<ll> coffs((int)mr.size(), 1);
        vector<ll> constants((int)mr.size(), 0);
        rep(i, (int)mr.size() - 1){
            // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first) を解く
            ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
            if (v < 0) v += mr[i].first;

            for (int j = i + 1; j < (int)mr.size(); j++) {
                (constants[j] += coffs[j] * v) %= mr[j].first;
                (coffs[j] *= mr[i].first) %= mr[j].first;
            }
        }

        return constants[(int)mr.size() - 1];
    }

    typedef NTT<167772161, 3> NTT_1;
    typedef NTT<469762049, 3> NTT_2;
    typedef NTT<1224736769, 3> NTT_3;

    //任意のmodで畳み込み演算 O(n log n)
    vector<ll> int32mod_convolution(vector<ll> a, vector<ll> b,int mod){
        for (auto& x : a) x %= mod;
        for (auto& x : b) x %= mod;
        NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
        auto x = ntt1.convolution(a, b);
        auto y = ntt2.convolution(a, b);
        auto z = ntt3.convolution(a, b);

        vector<ll> ret((int)x.size());
        vector<P> mr(3);
        rep(i, (int)x.size()){
            mr[0].first = ntt1.get_mod(), mr[0].second = (int)x[i];
            mr[1].first = ntt2.get_mod(), mr[1].second = (int)y[i];
            mr[2].first = ntt3.get_mod(), mr[2].second = (int)z[i];
            ret[i] = garner(mr, mod);
        }

        return ret;
    }

    // garnerのアルゴリズムを直書きしたversion，速い
    template<typename T> vector<T> fast_int32mod_convolution(vector<T> a, vector<T> b,int mod){
        for (auto& x : a) x %= mod;
        for (auto& x : b) x %= mod;
        
        NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
        assert(ntt1.get_mod() < ntt2.get_mod() && ntt2.get_mod() < ntt3.get_mod());
        auto x = ntt1.convolution(a, b);
        auto y = ntt2.convolution(a, b);
        auto z = ntt3.convolution(a, b);

        // garnerのアルゴリズムを極力高速化した
        const ll m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
        const ll m1_inv_m2 = mod_inv<ll>(m1, m2);
        const ll m12_inv_m3 = mod_inv<ll>(m1 * m2, m3);
        const ll m12_mod = m1 * m2 % mod;
        vector<ll> ret((int)x.size());
        rep(i, (int)x.size()){
            ll v1 = (y[i] - x[i]) *  m1_inv_m2 % m2;
            if (v1 < 0) v1 += m2;
            ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
            if (v2 < 0) v2 += m3;
            ll constants3 = (x[i] + m1 * v1 + m12_mod * v2) % mod;
            if (constants3 < 0) constants3 += mod;
            ret[i] = constants3;
        }

        return ret;
    }
};

int n ;
string S;
vector<vector<ll>> ddp;
vector<vector<ll>> dp;
vector<vector<ll>> ep;
vector<ll> X;
vector<ll> XX;

int main(){
    fast_input_output
    
}