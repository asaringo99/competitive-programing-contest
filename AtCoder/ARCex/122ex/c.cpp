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

TP f(ll n){
    int cnt = 1;
    ll x = 1, y = 0;
    while(x + y <= n){
        cnt++;
        if(cnt % 2 == 0){
            y = x + y;
        }
        else{
            x = x + y;
        }
        if(x == n || y == n) break;
    }
    return {x,y,cnt};
}

ll n ;

int main(){
    fast_input_output
    cin >> n ;
    set<int> st;
    bool s = true;
    auto[x,y,cnt] = f(n);
    st.insert(1);
    if(x > y){
        n -= x;
    }
    else{
        n -= y;
        s = false;
    }
    while(true){
        if(n == 0) break;
        auto[a,b,c] = f(n);
        c--;
        if(a > b){
            n -= a;
        }
        else{
            n -= b;
        }
        st.insert(cnt-c);
    }
    cout << endl;
    vector<int> res;
    rrep(i,1,cnt){
        if(s){
            if(st.count(i)) {
                if(i % 2 == 1) res.push_back(1);
                else res.push_back(2);
            }
            if(i % 2 == 1) res.push_back(4);
            else res.push_back(3);
        }
        else{
            if(st.count(i)) {
                if(i % 2 == 1) res.push_back(2);
                else res.push_back(1);
            }
            if(i % 2 == 1) res.push_back(3);
            else res.push_back(4);
        }
    }
    cout << res.size() << endl;
    for(int u : res) cout << u << endl;
}