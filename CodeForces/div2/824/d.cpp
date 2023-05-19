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

int z ;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> A(n,vector<int>(k));
    rep(i,n) rep(j,k) cin >> A[i][j];
    ll res = 0;
    rep(i,n){
        set<vector<int>> st;
        rep(j,n) st.insert(A[j]);
        vector<vector<int>> B;
        rep(j,n){
            vector<int> vec(k);
            rep(x,k) vec[x] = (A[i][x] + A[j][x]) % 3;
            B.push_back(vec);
        }
        ll sum = 0;
        for(auto V : B){
            vector<int> C(k);
            rep(x,k) C[x] = (3 - V[x]) % 3;
            if(st.count(C)) sum++;
        }
        sum /= 2;
        res += sum * (sum - 1) / 2;
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    solve();
}