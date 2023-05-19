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
int n, m, M;
int A[202020], L[202020], R[202020];
bool B[202020];
int ans[202020];
set<int> st, id;

void solve(){
    cin >> n >> M;
    m = M;
    rep(i,n) cin >> A[i];
    rep(i,n) st.insert(A[i]);
    rep(i,n) id.insert(i);
    ll res = 0;
    while(m > 0){
        vector<int> vec;
        for(int i : id){
            int pos = A[i];
            int l = ++L[i];
            int r = ++R[i];
            bool ok = false;
            if(st.count(pos+l) == 0){
                res += l;
                st.insert(pos+l);
                ok = true;
                --m;
                ans[m] = pos+l;
            }
            if(m == 0) break;
            if(st.count(pos-r) == 0){
                res += r;
                st.insert(pos-r);
                ok = true;
                --m;
                ans[m] = pos-r;
            }
            if(m == 0) break;
            if(!ok) vec.push_back(i);
        }
        for(int u: vec) id.erase(u);
    }
    cout << res << endl;
    rep(i,M) cout << ans[i] << " "; cout << endl;
}

int main(){
    fast_input_output
    solve();
}