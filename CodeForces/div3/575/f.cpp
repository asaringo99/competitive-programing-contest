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
typedef pair<ll,int> P ;
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

struct edge{
    int to;
    ll cost;
};

vector<edge> G[202020];
TP A[202020];
multiset<TP> st;
map<P,ll> mp;
ll d[202020];
int n, m, k;

void f(int s, int t, int c){
    rep(i,n) d[i] = 1e17;
    d[s] = 0;
    d[t] = c;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push({c,t});
    while(!que.empty()){
        auto [dist,v] = que.top(); que.pop();
        if(dist > d[v]) continue;
        for(edge e : G[v]){
            int u = e.to;
            if(d[u] > d[v] + e.cost){
                auto it = st.end(); it--;
                auto[top,a,b] = *it;
                d[u] = d[v] + e.cost;
                if(top < d[u]) continue;
                if(mp.count({min(u,s),max(u,s)})){
                    ll val = mp[{min(u,s),max(u,s)}];
                    if(st.count({val,min(u,s),max(u,s)})){
                        auto ite = st.find({val,min(u,s),max(u,s)});
                        st.erase(ite);
                        st.insert({min(d[u],val),min(u,s),max(u,s)});
                        mp[{min(u,s),max(u,s)}] = min(val,d[u]);
                    }
                    else{
                        st.erase(it);
                        st.insert({d[u],min(u,s),max(u,s)});
                        mp[{min(u,s),max(u,s)}] = d[u];
                    }
                }
                else{
                    st.erase(it);
                    st.insert({d[u],min(u,s),max(u,s)});
                    mp[{min(u,s),max(u,s)}] = d[u];
                }
                que.push({d[u],u});
            }
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        A[i] = {c,a,b};
    }
    sort(A,A+m);
    vector<tuple<int,int,int>> vec;
    rep(i,min(k,m)){
        auto [c,a,b] = A[i];
        st.insert({c,min(a,b),max(a,b)});
        mp[{min(a,b),max(a,b)}] = c;
    }
    if(k > m) rep(i,k-m) st.insert({1e17,-1,-1});
    rep(i,min(k,m)){
        auto [c,a,b] = A[i];
        auto it = st.end(); it--;
        auto [z,x,y] = *it;
        if(z > c){
            ll val = mp[{min(a,b),max(a,b)}];
            if(st.count({val,min(a,b),max(a,b)})){
                auto ite = st.find({val,min(a,b),max(a,b)});
                st.erase(ite);
                st.insert({min(c,val),min(a,b),max(a,b)});
                mp[{min(a,b),max(a,b)}] = min(val,c);
            }
            else{
                st.erase(it);
                st.insert({c,min(a,b),max(a,b)});
                mp[{min(a,b),max(a,b)}] = c;
            }
            f(a,b,c);
            f(b,a,c);
        }
    }
    auto it = st.end(); it--;
    auto[res,a,b] = *it;
    cout << res << endl;
}

int main(){
    fast_input_output
    solve();
}