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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

int n, q;
set<int> G[101];

int main(){
    fast_io
    cin >> n >> q;

    rep(i,q){
        int t, a, b;
        cin >> t;
        if(t == 1){
            cin >> a >> b;
            a--; b--;
            G[a].insert(b);
        }
        if(t == 2){
            cin >> a;
            a--;
            rep(j,n) if(G[j].count(a)){
                G[a].insert(j);
            }
        }
        if(t == 3){
            cin >> a;
            a--;
            set<int> st;
            for(int u : G[a]){
                for(int v : G[u]){
                    st.insert(v);
                }
            }
            for(int u : st) G[a].insert(u);
        }
    }
    rep(i,n) G[i].erase(i);
    rep(i,n){
        rep(j,n){
            if(G[i].count(j)) cout << "Y";
            else cout << "N";
        }
        cout << endl;
    }
}