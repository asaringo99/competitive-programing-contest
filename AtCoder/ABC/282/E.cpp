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

ll mod;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

vector<P> X[505];
vector<P> Y[505];
set<int> st;
bool used[505];

int n, N;
ll A[505];

void g(int k){
    used[k] = true;
    rep(u,N){
        if(used[u]) continue;
        Y[u].clear();
        rep(i,n){
            if(X[u][i].second != k) Y[u].push_back(X[u][i]);
        }
        swap(X[u],Y[u]);
    }
}

void f(set<int> &S){
    // cout << "S : ";
    // for(int u : S) cout << u << " "; cout << endl;
    ll val = 0;
    rep(i,n){
        set<int> T;
        ll mnv = 2e9;
        for(int u : S){
            chmin(mnv,X[u][n-i].first);
        }
        for(int u : S){
            if(mnv == X[u][n-i].first){
                T.insert(u);
            }
        }
        S = T;
        if(S.size() == 1){
            auto it = S.begin();
            g(*it);
        }
    }
    auto it = S.begin();
    g(*it);
}

int main(){
    fast_input_output
    cin >> n >> mod;
    N = n;
    rep(i,n) cin >> A[i];
    rep(i,n){
        st.insert(i);
        rep(j,n){
            if(i == j) continue;
            X[i].push_back({(powmod(A[i],A[j]) + powmod(A[j],A[i])) % mod, j});
        }
        sort(all(X[i]));
    }
    ll res = 0;
    while(n--){
        ll mnv = 2e9;
        rep(i,N){
            if(used[i]) continue;
            cout << i << " : ";
            rep(j,n) cout << X[i][j].first << " "; cout << endl;
        }
        rep(i,N) if(!used[i]) chmin(mnv,X[i][n-1].first);
        cout << mnv << endl;
        set<int> S;
        rep(i,N) if(!used[i] && mnv == X[i][n-1].first) S.insert(i);
        res += mnv;
        f(S);
        if(n == 1) break;
    }
    cout << res << endl;
}