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
    int res = 0;
    int X, Y;
    map<pair<int,int>,vector<pair<int,int>>> mp;
    rrep(x,100,101) {
        cout << x << endl;
        rrep(y,1,101){
            map<pair<int,int>,vector<pair<int,int>>> sv;
            set<pair<int,int>> st;
            int cnt = 0;
            rep(a,100) rrep(b,a+1,101){
                int s = (x + a) % b;
                int t = (y + a) % b;
                cnt++;
                st.insert({s,t});
                sv[{s,t}].push_back({a,b});
            }
            if(st.size() > res){
                cout << "OK" << endl;
                res = st.size();
                mp = sv;
                X = x;
                Y = y;
            }
        }
    }
    cout << X << " " << Y << " " << res << endl;
    for(auto[s,t] : mp){
        if(t.size() == 1) continue;
        cout << s.first << " " << s.second << " : ";
        for(auto[a,b] : t) cout << a << " " << b << ", ";
        cout << endl;
    }
}