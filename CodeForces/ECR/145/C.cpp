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
    ll n, k;
    cin >> n >> k;
    vector<bool> B(n,false);
    rep(i,n){
        if(n - i <= k){
            B[i] = true;
            k -= (n - i);
        }
    }
    ll sum = 0;
    vector<int> res(n);
    if(B[n-1]) res[n-1] = 1;
    else res[n-1] = -1;
    for(int i = n - 2; i >= 0; i--){
        ll val = 0, sum = 0;
        if(B[i]){
            rrep(j,i+1,n){
                sum += res[j];
                chmin(val,sum);
            }
            if(val < 0) res[i] = abs(val) + 1;
            else res[i] = 1;
        }
        else{
            rrep(j,i+1,n){
                sum += res[j];
                chmax(val,sum);
            }
            if(val > 0) res[i] = -abs(val) - 1;
            else res[i] = -1;
        }
    }
    rep(i,n) cout << res[i] << " "; cout << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}