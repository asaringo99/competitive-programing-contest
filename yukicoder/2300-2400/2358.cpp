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

int main(){
    fast_input_output
    cin >> n;
    vector<tuple<int,int,int>> tp;
    for(int x = 0; x * x <= n; x++){        
        for(int y = x; y * y <= n; y++){
            if(x == 0 && y == 0) continue;
            int N = n - x * y;
            int z = -1;
            if(N % (x + y) == 0) z = N / (x + y);
            if(z >= y) tp.push_back({x,y,z});
        }
    }
    set<tuple<int,int,int>> st;
    for(auto[x,y,z] : tp){
        if(!st.count({x,y,z})) st.insert({x,y,z});
        if(!st.count({x,z,y})) st.insert({x,z,y});
        if(!st.count({y,x,z})) st.insert({y,x,z});
        if(!st.count({y,z,x})) st.insert({y,z,x});
        if(!st.count({z,x,y})) st.insert({z,x,y});
        if(!st.count({z,y,x})) st.insert({z,y,x});
    }
    cout << st.size() << endl;
    for(auto[x,y,z] : st) cout << x << " " << y << " " << z << endl;
}