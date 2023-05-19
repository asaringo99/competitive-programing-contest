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

// 乱数発生器
random_device rnd ;
mt19937 mt(rnd()) ;
uniform_int_distribution<> rand100(1, 99) ;
const int random = rand100(mt);

struct RollingHash{
    int n ;
    const int base = 1007;
    const int mod = 1000000007;
    vector<ll> hash , power;

    RollingHash(string S){
        n = (int)S.size() ;
        hash.assign(n+1,0) ;
        power.assign(n+1,1) ;
        for(int i = 0 ; i < n ; i++){
            hash[i+1] = (hash[i] * base + S[i] + random) % mod ;
            // 各桁の底 二進数でいう2^0 2^1 2^2 ... 2^n
            power[i+1] = (power[i] * base) % mod ;
        }
    }

    // Sの[l,r]におけるハッシュ値を求める [2,4] => 2~4の文字列のハッシュ値
    // 1 <= l , r <= n
    inline int get_hash(int l , int r) const {
        ll res = (hash[r] - (hash[l-1] * power[r-l+1] % mod) + mod) % mod ;
        return res ;
    }

    // Longest Common Prefix
    // a文字目から始まる文字列とb文字目から始まる文字列が一致する最大の長さ
    // 1 <= a , b <= n
    inline int LCP(int a , int b) const {
        int low = 0 , high = n + 1 - max(a,b) ;
        while(high - low > 1){
            int mid = (low + high) / 2 ;
            if(get_hash(a,a+mid) != get_hash(b,b+mid)) high = mid ;
            else low = mid ;
        }
        return low ;
    }

    // hash h1 と長さ h2_len の文字列の hash h2 を結合
    int concat(int h1 , int h2 , int h2_len){
        return h1 * power[h2_len] + h2 % mod ;
    }
};

int n ;
string S, T;
vector<int> s[26], t[26];

int main(){
    fast_input_output
    cin >> n >> S >> T;
    rep(i,n){
        s[S[i]-'a'].push_back(i);
        t[T[i]-'a'].push_back(i);
    }
    S += S;
    T += T;
    
    rep(i,26){

    }
}