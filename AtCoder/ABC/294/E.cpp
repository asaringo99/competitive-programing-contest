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

ll L, n, m;
ll V[101010], S[101010];
ll U[101010], T[101010];
queue<pair<ll,ll>> A, B;

int main(){
    fast_io
    cin >> L >> n >> m;
    rep(i,n) cin >> V[i] >> S[i];
    rep(i,m) cin >> U[i] >> T[i];
    rep(i,n){
        A.push({V[i],S[i]});
    }
    rep(i,m){
        B.push({U[i],T[i]});
    }
    ll res = 0;
    while(1){
        auto[v,s] = A.front();
        auto[u,t] = B.front();
        if(s > t){
            if(v == u) res += t;
            B.pop();
            A.front().second -= t;
        }
        else{
            if(v == u) res += s;
            A.pop();
            B.front().second -= s;
            if(B.front().second == 0) B.pop();
        }
        if(A.empty() && B.empty()) break;
    }
    cout << res << endl;
}