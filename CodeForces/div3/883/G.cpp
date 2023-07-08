#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll;
typedef long double ld;
#define chmin(a,b) a = min(a,b);
#define chmax(a,b) a = max(a,b);
#define bit_count(x) __builtin_popcountll(x)
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl;
#define debug(a) cout << #a << " " << a << endl;
#define all(a) a.begin(), a.end()
#define endl "\n";
#define v1(n,a) vector<ll>(n,a)
#define v2(n,m,a) vector<vector<ll>>(n,v1(m,a))
#define v3(n,m,k,a) vector<vector<vector<ll>>>(n,v2(m,k,a))
#define v4(n,m,k,l,a) vector<vector<vector<vector<ll>>>>(n,v3(m,k,l,a))
template<typename T,typename U>istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T,typename U>ostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T>istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>istream &operator>>(istream&is,vector<vector<T>>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<vector<T>>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?"\n":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const set<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const multiset<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}

void wf(int n, int s, vector<vector<pair<int,ll>>> &G, vector<ll> &d){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    d[s] = 0;
    que.push({0,s});
    while(!que.empty()){
        auto[dist, v] = que.top(); que.pop();
        if(dist > d[v]) continue;
        for(auto [u, cost] : G[v]){
            if(d[u] > d[v] + cost){
                d[u] = d[v] + cost;
                que.push({d[u],u});
            }
        }
    }
}

void solve(){
    int n, m;
    string S;
    cin >> n >> m >> S;
    int start = 0;
    rep(x,S.size()) if(S[n-1-x] == '1') start |= 1 << x;
    vector<int> P(m), A(m), T(m);
    rep(i,m){
        int t;
        cin >> T[i];
        string o;
        cin >> o;
        int s = 0;
        rep(x,o.size()) if(o[n-1-x] == '1') s |= 1 << x;
        P[i] = s;
        cin >> o;
        s = 0;
        rep(x,o.size()) if(o[n-1-x] == '1') s |= 1 << x;
        A[i] = s;
    }
    vector<vector<pair<int,ll>>> G(1<<n);
    rep(bt, 1<<n){
        rep(i,m){
            int r = bt;
            int in = P[i];
            int out = A[i];
            rep(x,n){
                if((bt >> x & 1) && !(in >> x & 1)) out |= 1 << x;
            }
            G[bt].push_back({out,T[i]});
        }
    }
    auto dst = v1(1<<n,1e16);
    wf(n,start,G,dst);
    if(dst[0] == 1e16){
        pt(-1)
    } else {
        pt(dst[0]);
    }
}

int main(){
    fast_io
    int t = 1;
    cin >> t;
    rep(i,t) solve();
}