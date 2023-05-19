#include <bits/stdc++.h>
using namespace std ;
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
#define endl "\n"

int n , L ;

template<typename T> struct TpologicalSort{
    int n ; // ノード数
    vector<T> order ; // トポロジカルソート後のノードの並び
    vector<T> start ; // 始点ノード
    vector<T> end ; // 終点ノード

    // コンストラクタ
    TpologicalSort(int n_ , vector<int> *G){
        n = n_ ;
        build(G) ;
    }
    // トポロジカルソートを実施
    void build(vector<int> *G){
        vector<T> in(n,0) ;
        queue<int> que ;
        for(int i = 0 ; i < n ; i++){
            for(int u : G[i]) in[u]++ ;
        }
        for(int i = 0 ; i < n ; i++) if(in[i] == 0) {
            que.push(i) ;
            start.push_back(i) ;
        }
        while(!que.empty()){
            int v = que.front() ; que.pop() ;
            order.push_back(v) ;
            if(G[v].empty()) end.push_back(v) ;
            for(int u : G[v]) {
                in[u]-- ;
                if(in[u] == 0) que.push(u) ;
            }
        }
    }
    // 閉路判定: true: 閉路あり, false: 閉路なし, O(1)
    bool hasCycle(){
        int m = order.size() ;
        if(n != m) return true ;
        return false ;
    }
    vector<T> getStartNode() {return start ; }
    vector<T> getEndNode() {return end ; }
    inline int operator [] (int i) { return order[i] ; }
};

vector<int> G[101010] ;
int A[101010] ;
ll dp[101010] ;

int main(){
    cin >> n >> L ;
    rep(i,n) cin >> A[i] ;
    rep(i,n){
        if(i == 0 && A[i] > A[i+1]) G[i].push_back(i+1) ;
        if(i == n - 1 && A[i] > A[i-1]) G[i].push_back(i-1) ;
        if(0 < i && i < n - 1 && A[i] > A[i-1]){
            G[i].push_back(i-1) ;
        }
        if(0 < i && i < n - 1 && A[i] > A[i+1]){
            G[i].push_back(i+1) ;
        }
    }
    TpologicalSort<ll> tps(n,G) ;
    rep(i,n){
        int v = tps[i] ;
        ll val = L - A[v] ;
        for(int u : G[v]) chmax(dp[u],dp[v]+val) ;
    }
    vector<ll> vec = tps.getEndNode() ;
    ll res = 0 ;
    for(int u : vec) chmax(res,dp[u] + L - A[u]) ;
    cout << res << endl ;
}