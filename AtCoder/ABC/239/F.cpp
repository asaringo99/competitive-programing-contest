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

int n , m ;
int D[202020] ;
multiset<P> mst ;
set<int> G[202020] ;
vector<P> res ;
map<int,P> mp ;

int main(){
    cin >> n >> m ;
    int rem = n - m - 1 ;
    rep(i,n) cin >> D[i] ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].insert(b) ;
        G[b].insert(a) ;
    }
    rep(i,n) D[i] -= G[i].size() ;
    rep(i,n) {
        if(D[i] > 0) {
            mst.insert(P(-D[i],i)) ;
            mp[i] = P(-D[i],i) ;
        }
        if(D[i] < 0){
            cout << -1 << endl ;
            return 0 ;
        }
    }
    while(!mst.empty()){
        if(mst.size() == 1){
            cout << -1 << endl ;
            return 0 ;
        }
        auto it = mst.begin() ;
        P p = *it ;
        int v = p.second ;
        int d = p.first ;
        mst.erase(it) ;
        vector<P> vec ;
        for(int u : G[v]){
            P ar = mp[u] ;
            if(mst.count(ar) == 1){
                mst.erase(ar) ;
                vec.push_back(ar) ;
            }
        }
        it = mst.begin() ;
        while(it != mst.end() && d < 0){
            P q = *it ;
            mst.erase(it++) ;
            if(q.first + 1 < 0){
                mp[q.second] = P(q.first+1,q.second) ;
                vec.push_back(P(q.first+1,q.second)) ;
            }
            res.push_back(P(p.second + 1 , q.second + 1)) ;
            d++ ;
            rem-- ;
        }
        if(d < 0){
            cout << -1 << endl ;
            return 0 ;
        }
        for(P q : vec) mst.insert(q) ;
    }
    if(rem != 0){
        cout << -1 << endl ;
        return 0 ;
    }
    // rep(i,rem) res.push_back(P(n-1,n)) ;
    rep(i,res.size()) cout << res[i].first << " " << res[i].second << endl ;
}