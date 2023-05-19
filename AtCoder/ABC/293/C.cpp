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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int n;
int H, W;
ll A[12][12];

int res;
set<int> st;
map<int,int> mp;

void dfs(int x, int y){
    mp[A[x][y]]++;
    st.insert(A[x][y]);
    if(x == H - 1 && y == W - 1){
        if(st.size() == H + W - 1) res++;
    }
    if(x + 1 < H) dfs(x+1,y);
    if(y + 1 < W) dfs(x,y+1);
    mp[A[x][y]]--;
    if(mp[A[x][y]] == 0) st.erase(A[x][y]);
}

int main(){
    fast_io
    cin >> H >> W;
    rep(i,H) rep(j,W) cin >> A[i][j];
    dfs(0,0);
    cout << res << endl;
}