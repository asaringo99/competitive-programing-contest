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

int n ;
string T;

random_device rnd ;
mt19937 mt(rnd()) ;
uniform_int_distribution<> rand100(1, 99) ;
const int random1 = rand100(mt) , random2 = rand100(mt) ;

struct RollingHash{
    int n ;
    const int base1 = 1007 , base2 = 1009 ;
    const int mod1 = 1000000007 , mod2 = 1000000009 ;
    vector<ll> hash1 , hash2 , power1 , power2 ;

    RollingHash(string S){
        n = (int)S.size() ;
        hash1.assign(n+1,0) ;
        hash2.assign(n+1,0) ;
        power1.assign(n+1,1) ;
        power2.assign(n+1,1) ;
        for(int i = 0 ; i < n ; i++){
            hash1[i+1] = (hash1[i] * base1 + S[i] + random1) % mod1 ;
            hash2[i+1] = (hash2[i] * base2 + S[i] + random2) % mod2 ;
            // 各桁の底 二進数でいう2^0 2^1 2^2 ... 2^n
            power1[i+1] = (power1[i] * base1) % mod1 ;
            power2[i+1] = (power2[i] * base2) % mod2 ;
        }
    }

    // Sの[l,r]におけるハッシュ値を求める [2,4] => 2~4の文字列のハッシュ値
    // 1 <= l , r <= n
    inline P get_hash(int l , int r) const {
        ll res1 = (hash1[r] - (hash1[l-1] * power1[r-l+1] % mod1) + mod1) % mod1 ;
        ll res2 = (hash2[r] - (hash2[l-1] * power2[r-l+1] % mod2) + mod2) % mod2 ;
        return P(res1,res2) ;
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
    P concat(P h1 , P h2 , int h2_len){
        return make_pair((h1.first * power1[h2_len] + h2.first) % mod1 , (h1.second * power2[h2_len]+ h2.second) % mod2) ;
    }
};

int main(){
    // fast_io
    cin >> n ;
    int m = 2 * n;
    cin >> T;
    string U = T;
    reverse(all(U));
    RollingHash RH_T(T),  RH_U(U);
    string res = "";
    int idx = -1;
    rep(i,n+1){
        P hash1 = {0,0}, hash2 = {0,0};
        if(i > 0) hash1 = RH_T.get_hash(1,i);
        if(i < n) hash2 = RH_T.get_hash(n+i+1,2*n);
        P val;
        if(i == 0) val = hash2;
        else if(i == n) val = hash1;
        else val = RH_T.concat(hash1, hash2, n - i);

        if(RH_U.get_hash(n-i+1,2*n-i) == val){
            idx = i;
            rrep(x,n-i,2*n-i) res += U[x];
            cout << res << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}