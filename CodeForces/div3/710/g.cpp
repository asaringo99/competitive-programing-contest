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
int V[26];
set<P> st[26];

void solve(){
    int n;
    string S;
    cin >> S;
    n = S.size();
    rep(i,26) V[i] = 0;
    rep(i,26) st[i].clear();
    rep(i,n){
        int s = S[i] - 'a';
        chmax(V[s],i);
    }
    rep(i,n){
        int s = S[i] - 'a';
        st[s].insert({i,V[s]});
    }
    vector<bool> use(26,false);
    int cnt = 0;
    rep(i,26) if(V[i] == 1e9) {
        use[i] = true;
        cnt++;
    }
    int d = 0;
    vector<int> res;
    while(cnt < 26){
        ll a = 1e9;
        for(int i = 25 ; i >= 0 ; i--){
            if(use[i]) continue;
            if(st[i].empty()) continue;
            auto it = st[i].begin();
            P p = *it;
            auto [f,l] = p;
            chmin(a,l);
        }
        for(int i = 25 ; i >= 0 ; i--){
            if(use[i]) continue;
            if(st[i].empty()) continue;
            auto it = st[i].begin();
            P p = *it;
            auto [f,l] = p;
            if(f <= a) {
                res.push_back(i);
                d = f;
                use[i] = true;
                break;
            }
        }
        for(int i = 25 ; i >= 0 ; i--){
            if(use[i]) continue;
            if(st[i].empty()) continue;
            auto it = st[i].begin();
            while(it != st[i].end()){
                P p = *it;
                auto [f,l] = p;
                if(f <= d){
                    st[i].erase(it++);
                }
                else break;
            }
        }
        cnt++;
    }
    for(int u : res) cout << (char)('a' + u) ; cout << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}