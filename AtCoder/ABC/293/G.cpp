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

const int SQRT_Q = 1500 ;
int n, q;
ll A[202020];

vector<TP> vec[2020] ;
ll ans[2010101] ;
ll S[201010] ;

ll com(ll n){
    ll res = n * (n - 1) * (n - 2) / 3 / 2;
    return res;
}

int main(){
    fast_io
    cin >> n >> q;
    rep(i,n) cin >> A[i] ;

    rep(i,q){
        int l , r ;
        cin >> l >> r ;
        l-- ;
        vec[l/SQRT_Q].push_back({r,l,i}) ;
    }
    rep(i,SQRT_Q) sort(vec[i].begin(),vec[i].end()) ;
    int lef = 0 , rig = 0;
    ll res = 0 ;
    rep(i,SQRT_Q){
        for(TP tp : vec[i]){
            auto [rv,lv,id] = tp ;
            while(rig < rv){
                res -= com(S[A[rig]]);
                S[A[rig]]++ ;
                res += com(S[A[rig]]);
                rig++ ;
            }
            while(rig > rv){
                rig-- ;
                res -= com(S[A[rig]]);
                S[A[rig]]-- ;
                res += com(S[A[rig]]);
            }
            while(lef < lv){
                res -= com(S[A[lef]]);
                S[A[lef]]-- ;
                res += com(S[A[lef]]);
                lef++ ;
            }
            while(lef > lv){
                lef-- ;
                res -= com(S[A[lef]]);
                S[A[lef]]++ ;
                res += com(S[A[lef]]);
            }
            ans[id] = res ;
        }
    }
    rep(i,q) cout << ans[i] << endl ;
}