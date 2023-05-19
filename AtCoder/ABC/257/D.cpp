#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
TP A[202] ;

bool bfs(ll val){
    vector<int> G[202] ;
    rep(i,n){
        auto [p,x,y] = A[i] ;
        rep(j,n){
            if(i == j) continue;
            auto [vvv,nx,ny] = A[j] ;
            ll bo = abs(nx - x) + abs(ny - y) ;
            if(bo % val == 0){
                if(p >= bo / val) G[i].push_back(j) ;
            }
            else{
                if(p > bo / val) G[i].push_back(j) ;
            }
        }
    }
    rep(i,n){
        vector<bool> used(n,false) ;
        queue<int> que ;
        que.push(i) ;
        used[i] = true;
        while(!que.empty()){
            auto v = que.front() ; que.pop() ;
            for(int u : G[v]){
                if(used[u]) continue;
                used[u] = true ;
                que.push(u) ;
            }
        }
        bool ok = true ;
        rep(j,n) if(!used[j]) ok = false ;
        if(ok) return true ;
    }
    return false ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n){
        ll x , y , p ;
        cin >> x >> y >> p ;
        A[i] = {p,x,y} ;
    }
    ll lef = 0 , rig = 1e10 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(bfs(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}