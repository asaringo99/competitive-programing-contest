#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

// 座標圧縮
template<typename T=int> struct Compress{
    private:
        vector<int> vec ; // 元の値の座標圧縮後の値
        unordered_map<T,int> mp ; // 元の値 -> 変換された値
        vector<int> np ; // 変換された値 -> 元の値

        void build(vector<T> A){
            int n = A.size() ;
            np.resize(n);
            vector<T> B(n) ;
            for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
            vec.resize(n) ;
            sort(A.begin(),A.end()) ;
            for(int i = 0 ; i < n ; i++){
                auto it = lower_bound(A.begin(),A.end(),B[i]) ;
                int id = it - A.begin() ;
                vec[i] = id ;
                mp[B[i]] = id;
                np[id] = B[i] ;
            }
        }

    public:
        Compress(){}
        Compress(vector<T> A) { build(A); }
        size_t size() {return vec.size() ; }
        // 元の値 -> 変換された値
        inline int encrypt(T i) { return mp[i] ; }
        // 変換された値 -> 元の値
        inline T decrypt(int i) { return np[i] ; }
        vector<int> compress() { return vec; }
        vector<int> compress(vector<T> A) { build(A); return vec; }
        inline int operator [] (int i) { return vec[i] ; }
};

// function               : return              : description
// -----------------------------------------------------
// Compress()             : void          : コンストラクタ
// Compress(vector<ll> A) : void          : コンストラクタ, 座圧する
// encrypt(ll v)          : int           : 元の値 -> 座圧後の値
// decrypt(int v)         : ll            : 座圧後の値 -> 元の値
// compress()             : vector<int>   : 座圧後の値
// operator[i]            : int           : 座圧後の値の vector にアクセスすることが可能

int n, x;

struct edge{
    int to;
    ll cost;
    int id;
};

vector<edge> G[201010] ;
ll d[201010];
pair<int,int> prevv[201010] ; // 一個前のノード
vector<int> line ; // 経路復元

// 始点: s , 終点: t
void djikstra(int s , int t, int n){
    rep(i,n) d[i] = 1e16;
    rep(i,n) prevv[i] = {-1,-1} ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            int u = e.to;
            if(d[u] > d[v] + e.cost){
                d[u] = d[v] + e.cost ;
                prevv[u] = {v,e.id};
                que.push(P(d[u],u)) ;
            }
        }
    }
    // 始点から終点までの経路を復元する
    int v = t ;
    line = {} ;
    while(v != -1){
        int id = prevv[v].second;
        v = prevv[v].first;
        if(id != -1) line.push_back(id);
    }
    reverse(line.begin(),line.end()) ;
}

map<pair<int,int>,int> mp;

void solve(){
    cin >> n >> x;
    vector<tuple<int,int,int,int>> V;
    rep(i,n){
        int pos, dist, t, p;
        cin >> pos >> dist >> t >> p;
        int k = pos - p;
        int s = pos + dist;
        V.push_back({k,s,t + p,i});
    }
    sort(all(V));
    vector<int> A = {0, x};
    for(auto [k,s,t,i] : V){
        if(k < 0) continue;
        if(s > x) continue;
        A.push_back(k);
        A.push_back(s);
    }
    if(A.size() == 2){
        cout << x << endl;
        cout << 0 << endl;
        return;
    }
    Compress C(A);
    vector<int> S, T;
    rep(i,V.size()){
        auto [k,s,t,id] = V[i];
        if(k < 0) continue;
        if(s > x) continue;
        int a = C.encrypt(k);
        int b = C.encrypt(s);
        if(s-k>t){
            G[a].push_back({b,t,id});
        }
        else{
            G[a].push_back({b,s-k,-1});
        }
        S.push_back(k);
        T.push_back(s);
    }
    sort(all(S));
    sort(all(T));
    rep(i,S.size()-1){
        int s = S[i], ns = S[i+1];
        // cout << s << endl;
        int p = C.encrypt(s);
        int q = C.encrypt(ns);
        G[p].push_back({q, ns - s, -1});
        G[q].push_back({p, ns - s, -1});
    }
    rep(i,T.size()){
        int t = T[i];
        auto it = upper_bound(all(S), t);
        int q = C.encrypt(t);
        if(it != S.end()){
            int rr = *it;
            int r = C.encrypt(rr);
            G[q].push_back({r, rr - t, -1});
        }
        it--;
        int p = C.encrypt(*it);
        G[q].push_back({p, t - *it, -1});
    }
    auto it = S.begin();
    int p = *it;
    G[0].push_back({C.encrypt(p), p, -1});
    int m = C.encrypt(x);
    it = S.end(); it--;
    G[C.encrypt(*it)].push_back({m,x-*it, -1});
    it = T.end(); it--;
    G[C.encrypt(*it)].push_back({m,x-*it, -1});
    // rep(v,m+1) for(edge e : G[v]){
    //     cout << "s : " << v << " " << e.to << " " << e.cost << endl;
    // }
    djikstra(0,m,m+1);
    cout << d[m] << endl;
    cout << line.size() << endl;
    for(int u : line){
        cout << u + 1 << " ";
    }
    cout << endl;
}

int main(){
    fast_io
    solve();
}