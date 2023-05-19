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

map<int,int> mp;
set<int> st;

int n, q;

vector<tuple<int,int,int>> V;
int res[202020];

int main(){
    fast_input_output
    cin >> n;
    rep(i,n){
        int l, r, a;
        cin >> l >> r >> a;
        l--;
        V.push_back({l,1,a});
        V.push_back({r,0,a});
    }
    cin >> q;
    rep(i,q){
        int x;
        cin >> x;
        x--;
        V.push_back({x,2,i});
    }
    sort(all(V));
    rep(i,101010) st.insert(i);

    for(auto [i, o, a] : V){
        if(o == 2){
            res[a] = *(st.begin());
        }
        else if(o == 1){
            st.erase(a);
            mp[a]++;
        }
        else{
            mp[a]--;
            if(mp[a] == 0) st.insert(a);
        }
    }
    rep(i,q) cout << res[i] << endl;
}