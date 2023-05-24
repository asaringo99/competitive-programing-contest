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

void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll> A(n);
    vector<ll> L(n+1);
    vector<ll> R(n+1);

    vector<vector<int>> X(1010101);
    rep(i,n) cin >> A[i], X[A[i]].push_back(i);
    L[0] = -1;
    rrep(i,1,n){
        if(A[i-1] == A[i]) L[i] = L[i-1];
        else L[i] = i - 1;
    }
    R[n-1] = n+1;
    for(int i = n - 2; i >= 0; i--){
        if(A[i+1] == A[i]) R[i] = R[i+1];
        else R[i] = i + 1;
    }
    rep(i,q){
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        if(A[l] != x){
            cout << l + 1 << endl;
            continue;
        }
        if(A[r-1] != x){
            cout << r << endl;
            continue;
        }
        auto it = lower_bound(all(X[x]), l);
        int id = *it;
        if(L[id] < l && R[id] >= r){
            cout << -1 << endl;
            continue;
        }
        if(l <= L[id]){
            cout << L[id] + 1 << endl;
            continue;
        }
        if(R[id] < r){
            cout << R[id] + 1 << endl;
            continue;
        }
        cout << -1 << endl;
    }
}

int main(){
    fast_io
    solve();
}