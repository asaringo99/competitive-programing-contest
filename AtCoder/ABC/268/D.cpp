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

int n, m ;
string S[10], T[101010];
set<string> st;
bool used[10];
int sz;

vector<int> vec;
vector<int> str;
bool ok = false;
string res;

void make_str(int k, int d){
    if(d == n - 1){
        string X = "";
        rep(i,n-1){
            X += S[vec[i]];
            rep(j,str[i]+1) X += '_';
        }
        X += S[vec[n-1]];
        if(X.size() < 3) return;
        if(st.count(X) != 1) {
            ok = true;
            res = X;
        }
        return;
    }
    for(int i = 0 ; i <= k ; i++){
        str.push_back(i);
        make_str(k-i,d+1);
        str.pop_back();
    }
}

void dfs(int v){
    if(v == n){
        int k = 16 - sz;
        make_str(k,0);
    }
    rep(i,n){
        if(used[i]) continue;
        vec.push_back(i);
        used[i] = true;
        dfs(v+1);
        vec.pop_back();
        used[i] = false;
    }
}

int main(){
    fast_input_output
    cin >> n >> m ;
    sz = n - 1;
    rep(i,n) cin >> S[i], sz += S[i].size();
    rep(i,m){
        string t;
        cin >> t;
        st.insert(t);
    }
    dfs(0);
    if(ok) cout << res << endl;
    else cout << -1 << endl;
}