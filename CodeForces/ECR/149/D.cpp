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

void solve(){
    ll n;
    string S;
    cin >> n >> S;
    int sum = 0;
    for(char u : S){
        if(u == '(') sum++;
        else sum--;
    }
    if(sum != 0){
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n,-1), res(n,-1);
    queue<int> que;
    bool flg = false;
    rep(i,n){
        if(S[i] == '(') que.push(i);
        else{
            if(que.empty()) continue;
            int x = que.front(); que.pop();
            flg = true;
            ans[x] = flg;
            ans[i] = flg;
        }
    }
    bool ok = false;
    rep(i,n) if(ans[i] == -1) {
        ok = true;
        ans[i] = flg + ok;
    }
    
    queue<int> Q;
    bool flfl = false;
    rep(i,n){
        if(S[n-1-i] == '(') Q.push(n-1-i);
        else{
            if(Q.empty()) continue;
            int x = Q.front(); Q.pop();
            flfl = true;
            res[x] = flfl;
            res[n-1-i] = flfl;
        }
    }
    bool gd = false;
    rep(i,n) if(res[i] == -1) {
        gd = true;
        res[i] = flfl + gd;
    }
    if(flg+ok < flfl+gd){
        cout << flg + ok << endl;
        for(int u : ans) cout << u << " "; cout << endl;
    }
    else{
        cout << flfl + gd << endl;
        for(int u : res) cout << u << " "; cout << endl;
    }
}

int main(){
    // fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}