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
    int n, q;
    cin >> n >> q;
    vector<int> A(n), S(n);
    rep(i,n) cin >> A[i];
    rep(i,n) S[i] = i > 0 ? max(A[i],S[i-1]) : A[i];
    rep(i,q){
        int a, k;
        cin >> a >> k;
        a--;
        if(S[a] > A[a]){
            cout << 0 << endl;
            continue;
        }
        auto it = upper_bound(S.begin(),S.end(),A[a]);
        int id = it - S.begin(); 
        if(a > 1) k -= a - 1 ;
        if(k <= 0){
            cout << 0 << endl;
            continue;
        }
        if(id == n){
            cout << k << endl;
            continue;
        }
        else{
            if(a == 0){
                cout << min(id - a - 1, k) << endl;
                continue;
            }
            int res = min(id-a,k);
            cout << res << endl;
        }
    }
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}