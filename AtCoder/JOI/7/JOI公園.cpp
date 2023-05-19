#include <bits/stdc++.h>
using namespace std ;
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
#define distance(sx,sy,gx,gy) (sx - gx) * (sx - gx) + (sy - gy) * (sy - gy)
#define endl "\n"

struct edge{
    int to ;
    ll cost ;
};

ll n , m , c ;
vector<edge> G[101010] ;
ll d[101010] ;
ll res, sum, ans;
set<int> st ;
map<P,ll> mp ;
map<P,bool> use ;

void djikstra(){
    rep(i,n) d[i] = 1e16 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.emplace(0,0) ;
    while(!que.empty()){
        auto[dist,v] =  que.top() ; que.pop() ;
        if(d[v] < dist) continue;
        sum = c * dist ;
        for(edge e : G[v]){
            if(st.count(e.to) == 1 && !use[(P(min(e.to,v),max(e.to,v)))]){
                use[(P(min(e.to,v),max(e.to,v)))] = true ;
                res -= mp[P(min(e.to,v),max(e.to,v))] ;
            }
        }
        st.insert(v) ;
        chmin(ans,res+sum) ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.emplace(d[e.to],e.to) ;
            }
        }
    }
}

int main(){
    cin >> n >> m >> c ;
    rep(i,m){
        int a , b ,c ;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
        res += c ;
        mp[P(min(a,b),max(a,b))] = c ;
    }
    sum = 0, ans = 1e18;
    djikstra() ;
    cout << ans << endl;
}