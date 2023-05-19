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

int n , m , q ;
P A[202020] ;
int used[202020] ;
vector<int> G[202020] ;
set<int> F[202020] ;
ll d[202020] ;
set<P> st;

void djikstra(){
    rep(i,n) d[i] = 1e16 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push({0,0}) ;
    while(!que.empty()){
        auto[dist,v] = que.top() ; que.pop() ;
        if(d[v] < dist) continue;
        for(int u : G[v]){
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                que.push({d[u],u}) ;
            }
        }
    }
}

void dfs(int v , int prev, int &cnt){
    if(st.count(P(prev,v))) return;
    if(used[v] == 0) return;
    used[v]--;
    st.insert(P(prev,v));
    if(used[v] == 0){
        cnt++;
        for(int u : F[v]){
            if(st.count(P(v,u))) continue;
            dfs(u,v,cnt);
        }
    }
}


int main(){
    fast_input_output;
    cin >> n >> m >> q ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b);
        G[b].push_back(a);
        A[i] = {a,b} ;
    }
    djikstra();
    rep(v,n){
        for(int u : G[v]) if(d[u] - d[v] == 1) F[v].insert(u) , used[u]++ ;
    }
    int res = 0;
    rep(i,q){
        int a;
        cin >> a;
        a--;
        auto[u,v] = A[a];
        if(F[u].count(v) == 1) {
            dfs(v,u,res);
        }
        if(F[v].count(u) == 1) {
            dfs(u,v,res);
        }
        cout << res << endl ;
    }
}