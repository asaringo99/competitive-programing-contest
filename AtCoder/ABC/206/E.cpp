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

int l , r ;
int prime_factor[1000007] ;

void ertstns(){
    memset(prime_factor,-1,sizeof(prime_factor)) ;
    prime_factor[0] = prime_factor[1] = 1 ;
    ll sum = 0 ;
    for(int i = 2 ; i <= 1000000 ; i++){
        ll val = 0 ;
        if(prime_factor[i] == -1){
            for(int j = i ; j <= 1000000 ; j += i) prime_factor[j] = i ;
        }
    }
}

int main(){
    cin >> l >> r ;
    ertstns() ;
    ll res = 0 ;
    for(int i = 2 ; i <= r ; i++){
        set<int> st ;
        bool ok = true ;
        int pf = i ;
        while(pf != 1){
            if(st.count(prime_factor[pf]) == 1) ok = false ;
            st.insert(prime_factor[pf]) ;
            pf /= prime_factor[pf] ;
        }
        if(!ok) continue ;
        ll sum = r / i - (l - 1) / i ;
        if(st.size() % 2 == 1) res += sum * (sum - 1) / 2 ;
        else res -= sum * (sum - 1) / 2 ;
    }
    for(int i = max(l,2) ; i <= r ; i++) res -= (r / i - 1) ;
    cout << res * 2 << endl ;
}