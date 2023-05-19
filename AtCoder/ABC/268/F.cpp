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

struct F{
    ll x , cnt;
    int id;
    F(int a_, int b_, int id_): x(a_), cnt(b_), id(id_) {}

    bool operator< (const F& y) const {
        return x * y.cnt > cnt * y.x ;
    }
    bool operator> (const F& y) const {
        return x * y.cnt < cnt * y.x ;
    }
};

int n ;
string S[202020];

int main(){
    fast_input_output
    cin >> n ;
    vector<F> vec;
    rep(i,n) {
        cin >> S[i];
        int x = 0, s = 0;
        for(char u : S[i]){
            if(u == 'X') x++;
            else s += (u - '0');
        }
        vec.push_back({x,s,i});
    }
    sort(vec.begin(), vec.end());
    string X = "";
    rep(i,n){
        auto[x,cnt,id] = vec[i];
        X += S[id];
    }
    ll res = 0;
    int x = 0;
    rep(i,X.size()){
        if(X[i] == 'X') x++;
        else res += (X[i] - '0') * x;
    }
    cout << res << endl;
}