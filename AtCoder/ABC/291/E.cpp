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

int n, m;
int A[202020], B[202020];
int X[202020];
vector<int> G[202020];
set<pair<int,int>> st;
int res[202020];

int main(){
    fast_io
    cin >> n >> m;
    rep(i,m) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        if(st.count({A[i],B[i]})) continue;
        st.insert({A[i],B[i]});
        X[A[i]]++;
        G[B[i]].push_back(A[i]);
    }
    int cnt = 0;
    int idx = -1;
    rep(i,n){
        if(X[i] == 0){
            cnt++;
            idx = i;
        }
    }
    if(cnt > 1 || cnt == 0){
        cout << "No" << endl;
        return 0;
    }
    int val = n;
    queue<int> que;
    que.push(idx);
    while(!que.empty()){
        int v = que.front(); que.pop();
        res[v] = val;
        val--;
        for(int u: G[v]){
            X[u]--;
            if(X[u] == 0) que.push(u);
        }
        if(que.size() > 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i,n) cout << res[i] << " "; cout << endl;
}