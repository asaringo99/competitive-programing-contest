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

void solve(){
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    rep(i,n){
        char a;
        cin >> a;
        A[i] = a - '0';
    }
    rep(i,n){
        char a;
        cin >> a;
        B[i] = a - '0';
    }
    if(A[0] != B[0] || A[n-1] != B[n-1]){
        cout << -1 << endl;
        return;
    }
    vector<pair<int,int>> X, Y;
    bool ok = false;
    rep(i,n){
        if(A[i] == 1){
            if(!ok) X.push_back({i,i});
            else{
                X[X.size()-1].second = i;
            }
            ok = true;
        }
        else ok = false;
    }
    ok = false;
    rep(i,n){
        if(B[i] == 1){
            if(!ok) Y.push_back({i,i});
            else{
                Y[Y.size()-1].second = i;
            }
            ok = true;
        }
        else ok = false;
    }
    if(X.size() != Y.size()){
        cout << -1 << endl;
        return;
    }
    n = X.size();
    ll res = 0;
    rep(i,n){
        auto[xl,xr] = X[i];
        auto[yl,yr] = Y[i];
        res += abs(xl - yl) + abs(xr - yr);
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    int z;
    cin >> z;
    rep(i,z) solve();
}