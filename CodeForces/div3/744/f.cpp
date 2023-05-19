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
    int n, d;
    cin >> n >> d;
    vector<int> A(n);
    vector<bool> use(n,false);
    rep(i,n) cin >> A[i];
    int res = 0;
    rep(i,n){
        if(use[i]) continue;
        use[i] = true;
        int a = A[i];
        int k = i;
        (k += d) %= n;
        int cnt = 0;
        bool ok = false;
        if(a == 1) cnt = 1;
        else ok = true;
        while(k != i){
            chmax(res,cnt);
            use[k] = true;
            if(A[k] == 0) cnt = 0, ok = true;
            else cnt++;
            k += d;
            k %= n;
            chmax(res,cnt);
        }
        (k += d) %= n;
        if(a == 1) cnt++;
        else cnt = 0;
        while(k != i){
            chmax(res,cnt);
            use[k] = true;
            if(A[k] == 0) cnt = 0, ok = true;
            else cnt++;
            k += d;
            k %= n;
            chmax(res,cnt);
        }
        if(!ok){
            cout << -1 << endl;
            return;
        }
    }
    cout << res << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}