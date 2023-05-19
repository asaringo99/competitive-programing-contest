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

int n ;
int A[1010];
set<int> st;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    sort(A,A+n);
    queue<int> que;
    que.push(A[0]);
    while(!que.empty()){
        int a = que.front(); que.pop();
        st.insert(a);
        if(a % 2 == 0) que.push(a/2);
        if(a % 3 == 0) que.push(a/3);
    }
    ll res = 1e18;
    for(int u : st){
        ll cnt = 0;
        bool ok = true;
        rep(i,n) {
            if(A[i] % u == 0){
                int div = A[i] / u;
                while(div % 2 == 0){
                    div /= 2;
                    cnt++;
                }
                while(div % 3 == 0){
                    div /= 3;
                    cnt++;
                }
                if(div != 1){
                    ok = false;
                }
            }
            else ok = false;
        }
        if(ok) chmin(res,cnt);
    }
    if(res == 1e18) res = -1;
    cout << res << endl;
}