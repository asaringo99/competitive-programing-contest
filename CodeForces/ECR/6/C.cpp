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
    cin >> n;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    set<int> st;
    int res = 0;
    vector<pair<int,int>> vec;
    int bef = 0;
    rep(i,n){
        if(st.count(A[i])){
            vec.push_back({bef+1,i+1});
            bef = i + 1;
            st = {};
            res++;
        }
        else st.insert(A[i]);
    }
    if(vec.empty()){
        cout << -1 << endl;
    }
    else{
        if(!st.empty()) vec.back().second = n;
        cout << vec.size() << endl;
        for(auto[a,b] : vec){
            cout << a << " " << b << endl;
        }
    }
}

int main(){
    fast_io
    solve();
}