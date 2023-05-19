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

int z ;

void solve(){
    int n; string S;
    cin >> n >> S;
    vector<int> p(n);
    vector<bool> use(n,false);
    rep(i,n) cin >> p[i], p[i]--;
    ll ans = 1;
    rep(i,n){
        if(use[i]) continue;
        int k = p[i];
        vector<int> vec = {i}, tmp;
        int m = 1;
        while(k != i){
            vec.push_back(k);
            use[k] = true;
            k = p[k];
            m++;
        }
        tmp = vec;
        ll res = vec.size();
        rep(i,m){
            rep(j,m) vec[j] = p[vec[j]];
            bool ok = true;
            rep(j,m) if(S[vec[j]] != S[tmp[j]]) ok = false;
            if(ok){
                res = i + 1;
                break;
            }
        }
        ans = lcm(ans,res);
    }
    cout << ans << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}