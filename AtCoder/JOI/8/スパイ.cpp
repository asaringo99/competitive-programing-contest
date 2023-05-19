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

vector<int> J[2020] , I[2020] ;
int di[2020] , S[2020] ;
vector<int> mp[2020] ;
int res[2020] ;

void dfs_i(int v , int prev , int sum){
    sum += S[v] ;
    di[v] += sum ;
    for(int u : I[v]){
        if(u == prev) continue;
        dfs_i(u,prev,sum) ;
    }
    S[v] = 0 ;
}

void dfs_j(int v , int prev){
    for(int u : mp[v]) S[u] += 1 ;
    dfs_i(0,-1,0) ;
    res[v] = di[v] ;
    for(int u : J[v]){
        if(u == prev) continue;
        dfs_j(u,v) ;
    }
    for(int u : mp[v]) S[u] += -1 ;
    dfs_i(0,-1,0) ;
}

int main(){
    cin >> n >> m ;
    rrep(i,1,n+1){
        int a , b ;
        cin >> a >> b ;
        I[a].push_back(i) ;
        J[b].push_back(i) ;
    }
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        mp[b].push_back(a) ;
    }
    dfs_j(0,-1) ;
    rrep(i,1,n+1) cout << res[i] << endl ;
}