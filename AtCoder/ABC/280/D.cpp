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
#define all(a) a.begin(), a.end()
#define endl "\n"

ll k , a;

int main(){
    fast_input_output
    cin >> k;
    a = k;
    vector<P> vec;
    for(ll i = 2 ; i * i <= k ; i++){
        if(k % i != 0) continue;
        int ex = 0;
        while(k % i == 0){
            k /= i;
            ex++;
        }
        vec.push_back({i,ex});
    }
    if(k != 1) vec.push_back({k,1});
    ll res = 0;
    for(auto [u, ex] : vec){
        for(ll i = u ; i <= a ; i += u){
            ll x = i;
            while(x % u == 0){
                x /= u;
                ex--;
            }
            if(ex <= 0){
                chmax(res,i);
                break;
            }
        }
    }
    cout << res << endl;
}