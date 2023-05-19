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
#define endl "\n"

int n ;
char C[1000][1000];

int main(){
    fast_input_output
    rep(i,9) rep(j,9) cin >> C[i][j];
    int res = 0;
    set<vector<P>> st;
    rep(i,9) rep(j,9){
        if(C[i][j] == '#'){
            rep(d,10) rep(e,10) {
                if(d == 0 && e == 0) continue;
                if(j + d - e < 0) continue;
                if(j - e < 0) continue;
                if(C[i+e][j+d] != '#') continue;
                if(C[i+e+d][j+d-e] != '#') continue;
                if(C[i+d][j-e] != '#') continue;
                vector<P> vec;
                vec.push_back({i+e,j+d});
                vec.push_back({i+e+d,j+d-e});
                vec.push_back({i+d,j-e});
                vec.push_back({i,j});
                sort(vec.begin(),vec.end());
                st.insert(vec);
            }
            rep(d,10) rep(e,10) {
                if(d == 0 && e == 0) continue;
                if(j + d - e < 0) continue;
                if(j - e < 0) continue;
                if(C[i+d][j+e] != '#') continue;
                if(C[i+d-e][j+e+d] != '#') continue;
                if(C[i-e][j+d] != '#') continue;
                vector<P> vec;
                vec.push_back({i+d,j+e});
                vec.push_back({i+d-e,j+e+d});
                vec.push_back({i-e,j+d});
                vec.push_back({i,j});
                sort(vec.begin(),vec.end());
                st.insert(vec);
            }
            rep(d,10) rep(e,10) {
                if(d == 0 && e == 0) continue;
                if(j + d - e < 0) continue;
                if(j - d < 0) continue;
                if(C[i+e][j+d] != '#') continue;
                if(C[i+e+d][j+d-e] != '#') continue;
                if(C[i+d][j-e] != '#') continue;
                vector<P> vec;
                vec.push_back({i+e,j+d});
                vec.push_back({i+e+d,j+d-e});
                vec.push_back({i+d,j-e});
                vec.push_back({i,j});
                sort(vec.begin(),vec.end());
                st.insert(vec);
            }
        }
    }
    cout << st.size() << endl;
}