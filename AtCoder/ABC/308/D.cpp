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

vector<int> G[402020] ;

ll bfs(int start, int n){
    vector<ll> d(n,1e16);
    d[start] = 0 ;
    queue<int> que ;
    que.push(start) ;
    while(!que.empty()){
        int v = que.front(); que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                que.push(u);
            }
        }
    }
    ll res = 0;
    rep(i,n) {
        if(d[i] == 1e16) continue;
        chmax(res,d[i]);
    }
    return res;
}


void solve(){
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    int n = n1 + n2;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    pt(bfs(0,n)+bfs(n1+n2-1,n)+1);
}

int main(){
    fast_io
    int t = 1;
    // cin >> t;
    rep(i,t) solve();
}