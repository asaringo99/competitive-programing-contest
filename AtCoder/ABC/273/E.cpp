#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC optimize("O3")
// #pragma GCC target("avx")
#pragma GCC target("avx2")
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

int n;
int q;
vector<int> query[505050];
int res[505050];
vector<pair<int,int>> G[505050];
map<int,int> mp;
set<int> st;
int prevv[505050];

vector<int> A;

void dfs(int v){
    for(int u: query[v]){
        res[u] = A.empty() ? -1 : A[A.size()-1];
    }
    for(P p : G[v]){
        auto [nx, val] = p;
        A.push_back(val);
        dfs(nx);
        A.pop_back();
    }
}

int main(){
    fast_input_output
    cin >> q;
    int state = 0;
    st.insert(0);
    rep(i,q){
        string s;
        int t;
        cin >> s;
        if(s == "ADD"){
            cin >> t;
            auto it = st.end(); it--;
            int now = state;
            state = *it;
            state++;
            prevv[state] = now;
            G[now].push_back({state,t});
            st.insert(state);
        }
        if(s == "DELETE"){
            state = prevv[state];
            if(state < 0) state = 0;
        }
        if(s == "SAVE"){
            cin >> t;
            mp[t] = state;
        }
        if(s == "LOAD"){
            cin >> t;
            state = mp[t];
        }
        query[state].push_back(i);
    }
    dfs(0);
    rep(i,q) cout << res[i] << " "; cout << endl;
}