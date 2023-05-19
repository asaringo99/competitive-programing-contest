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
    int n, m;
    string S;
    cin >> S >> m;
    vector<int> B(m), C(m,0);
    rep(i,m) cin >> B[i];
    n = S.size();
    vector<char> A(26,0), res(m);
    vector<bool> use(m,false);
    rep(i,n) A[S[i]-'a']++;
    int s = 25, cnt = 0;
    while(cnt < m){
        vector<int> vec;
        rep(i,m) {
            if(use[i]) continue;
            if(B[i] == C[i]){
                vec.push_back(i);
            }
        }
        int k = vec.size();
        for(int i = s ; i >= 0 ; i--){
            if(A[i] >= k){
                s = i;
                break;
            }
        }
        for(int u : vec){
            res[u] = char('a' + s);
            cnt++;
            use[u] = true;
        }
        for(int u : vec){
            rep(i,m){
                if(use[i]) continue;
                C[i] += abs(i - u);
            }
        }
        s--;
    }
    for(char u : res) cout << u; cout << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}