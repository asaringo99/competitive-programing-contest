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

int n;

set<int> st;

int main(){
    fast_input_output
    cin >> n;
    vector<int> bt(30,0);
    int cnt = 0;
    rep(i,n){
        int t, x;
        cin >> t;
        if(t == 1){
            cin >> x;
            if(!st.count(x)) {
                rep(j,30) if(x >> j & 1) bt[j]++;
                st.insert(x);
                cnt++;
            }
        }
        if(t == 2){
            cin >> x;
            if(st.count(x)) {
                rep(j,30) if(x >> j & 1) bt[j]--;
                st.erase(x);
                cnt--;
            }
        }
        if(t == 3){
            if(st.empty()){
                cout << -1 << endl;
                continue;
            }
            ll res = 0;
            rep(j,30) if(bt[j] == cnt) res |= 1 << j;
            cout << res << endl;
        }
    }
}