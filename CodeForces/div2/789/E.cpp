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
typedef pair<int,int> P ;
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
int A[202020], B[202020];
vector<int> X;
vector<bool> used;

int dfs(int v, int c){
    if(used[v]) return c;
    used[v] = true;
    int y = X[v];
    return dfs(y,c+1);
}

vector<int> odd, eve;

void solve(){
    X.clear();
    used.clear();
    odd.clear();
    eve.clear();
    cin >> n;
    rep(i,n) cin >> A[i], A[i]--;
    rep(i,n) cin >> B[i], B[i]--;
    X.resize(n);
    used.resize(n,false);
    rep(i,n) X[A[i]] = B[i];
    vector<int> vec;
    rep(i,n){
        if(used[i]) continue;
        int k = dfs(i,0);
        if(k % 2 == 0) eve.push_back(k);
        else odd.push_back(k);
    }
    sort(all(odd),greater<int>());
    sort(all(eve),greater<int>());
    ll res = 0;
    int l = 1, r = n;
    for(int u : eve){
        rep(i,u/2){
            res += r--;
            res -= l++;
        }
    }
    for(int u : odd){
        rep(i,u/2){
            res += r--;
            res -= l++;
        }
    }
    cout << res * 2 << endl;
}

int main(){
    int z;
    cin >> z;
    rep(i,z) solve();
}