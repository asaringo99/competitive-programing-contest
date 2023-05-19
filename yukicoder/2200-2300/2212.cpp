#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
int res[2020][2020];

void f(int x, int y, int cnt){
    if(cnt == 0) return;
    rrep(i,x,x+cnt) rrep(j,y,y+cnt) res[i][j] = 1;
    if(cnt == 1) res[x+1][y+1] = 1;
    if(y != 0) f(x+cnt,y,cnt/2);
    f(x,y+cnt,cnt/2);
}


int main(){
    fast_input_output
    cin >> n;
    if(n == 1){
        cout << -1 << endl;
        return 0;
    }
    set<int> st;
    rep(i,1<<(2*n)) if(i % 2 == 0) st.insert(i);
    int val = 1;
    f(0,0,(1<<(n-1)));
    rrep(i,1<<(n-1),1<<n) rep(j,1<<(n-1)){
        res[i][j] = (res[i-(1<<(n-1))][j+(1<<(n-1))] ^ 1);
    }
    int c = 0;
    rep(i,1<<(n-1)) rep(j,1<<(n-1)){
        res[i][j] += c;
        res[i+(1<<(n-1))][j+(1<<(n-1))] += c;
        c += 2;
    }
    rep(i,1<<(n-1)) rep(j,1<<(n-1)){
        res[i+(1<<(n-1))][j] += c;
        res[i][j+(1<<(n-1))] += c;
        c += 2;
    }
    rep(i,1<<n){
        rep(j,1<<n) cout << res[i][j] << " "; cout << endl;
    }
}