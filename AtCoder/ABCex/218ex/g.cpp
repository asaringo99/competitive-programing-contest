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

int n ;
ll A[101010] ;
vector<int> G[101010] ;

template<typename T>
struct Median{

    private :
        multiset<T> lef , rig ;

        void push_(T x){
            lef.insert(x) ; rig.insert(x) ;
            auto lit = lef.end() ; lit-- ;
            auto rit = rig.begin() ;
            T l = *lit , r = *rit ;
            lef.erase(lef.find(l)) ;
            rig.erase(rig.find(r)) ;
            if(l > r) swap(l,r) ;
            lef.insert(l) ;
            rig.insert(r) ;
        }

        T get_(bool type){
            if(type) {
                auto lit = lef.end() ; lit-- ;
                auto rit = rig.begin() ;
                T l = *lit , r = *rit ;
                return (l + r) / 2 ;
            }
            else {
                auto it = lef.end() ; it-- ;
                T res = *it ;
                return res ;
            }
        }

        void erase_(T x){
            T val = x ;
            if(lef.count(val) >= 2){
                lef.erase(lef.find(val)) ;
                lef.erase(lef.find(val)) ;
                auto it = rig.begin() ;
                lef.insert(*it) ;
                rig.erase(it) ;
            }
            else if(rig.count(val) >= 2){
                rig.erase(rig.find(val)) ;
                rig.erase(rig.find(val)) ;
                auto it = lef.end() ; it-- ;
                rig.insert(*it) ;
                lef.erase(it) ;
            }
            else{
                lef.erase(lef.find(val)) ;
                rig.erase(rig.find(val)) ;
            }
        }
    public :
        void push(T x) { return push_(x) ; }
        void erase(T x) { erase_(x) ; }
        T get(bool type = false) { return get_(type) ;}
};

Median<ll> median ;

inline ll dfs(int v , int prev , int p){
    median.push(A[v]) ;
    if(v != 0 && G[v].size() == 1) {
        ll res = median.get(true) ;
        median.erase(A[v]) ;
        return res ;
    }
    ll val ;
    if(p == 0){
        val = -1e15 ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(u == prev) continue ;
            chmax(val,dfs(u,v,1)) ;
        }
    }
    else{
        val = 1e15 ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(u == prev) continue ;
            chmin(val,dfs(u,v,0)) ;
        }
    }
    median.erase(A[v]) ;
    return val ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    cout << dfs(0,-1,0) << endl ;
}