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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

int n , m ;
vector<int> G[10101] ;
int A[10101] , B[10101] ;
bool used[10101] ;

int dfs(int v){
    int res = 0 ;
    if(!used[v]) res += A[v] ;
    if(G[v].size() == 0) return res ;
    vector<P> vec ;
    for(int u : G[v]){
        vec.push_back(P(res+dfs(u),u)) ;
    }
    sort(vec.begin(),vec.end(),greater<P>()) ;
    auto[ret,node] = vec[0] ;
    B[v] = node ;
    return ret ;
}

int main(){
    cin >> n >> m ;
    rrep(i,1,n+1){
        int s, a ;
        cin >> s >> a;
        G[s].push_back(i) ;
        A[i] = a ;
    }
    int res = 0 ;
    rep(i,m){
        rep(j,n+1) B[j] = -1 ;
        res += dfs(0) ;
        int v = 0 ;
        while(v != -1){
            used[v] = true ;
            v = B[v] ;
        }
    }
    cout << res << endl ;
}