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
typedef pair<ll,int> P ;
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

TP A[202020];
ll d[808][808];
map<int,int> mp ;
map<int,int> cp ;
int n, m, k;
int num;

void f(){
    rep(k,num) rep(i,num) rep(j,num) chmin(d[i][j],d[i][k]+d[k][j]);
}

void solve(){
    cin >> n >> m >> k;
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        A[i] = {c,a,b};
    }
    sort(A,A+m);
    rep(i,808) rep(j,808) d[i][j] = 1e16;
    rep(i,min(k,m)){
        auto [c,a,b] = A[i];
        if(!mp.count(a)) {
            cp[num] = a;
            mp[a] = num++;
        }
        if(!mp.count(b)) {
            cp[num] = b;
            mp[b] = num++;
        }
        d[mp[a]][mp[b]] = c;
        d[mp[b]][mp[a]] = c;
    }
    f();
    vector<ll> vec;
    rep(i,num) rep(j,num) if(cp[i] < cp[j]) {
        vec.push_back(d[i][j]);
    }
    sort(vec.begin(),vec.end());
    cout << vec[k-1] << endl;
}

int main(){
    fast_input_output
    solve();
}