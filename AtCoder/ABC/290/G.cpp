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

int n;
ll A[202020];
vector<int> D[202020];
vector<vector<ll>> S;

int main(){
    fast_io
    cin >> n;
    rep(i,n) cin >> A[i], A[i]--;
    S.resize(n);
    rep(i,n) S[i].push_back(0);
    // rep(i,n) D[i].push_back(0);
    ll res = 0;
    rep(i,n){
        D[A[i]].push_back(i);
        ll rem = n - i - 1;
        if(i <= rem){
            res += i * (i + 1) / 2;
            ll sz = S[A[i]].size();
            res -= S[A[i]][sz-1];
        }
        else{
            ll same = i - rem;
            res += rem * (rem + 1) / 2;
            res += same * (rem + 1);
            // cout << "r : " << res << endl;
            auto it = upper_bound(all(D[A[i]]), rem);
            ll idx = it - D[A[i]].begin();
            // cout << "D[" << A[i] << "] :";
            // for(ll u : D[A[i]]) cout << u << " "; cout << endl;
            // cout << "id: " << idx << endl;
            ll sec = D[A[i]].size() - idx - 1;
            res -= sec * (rem + 1);
            res -= S[A[i]][idx];
        }
        // cout << res << endl;
        ll sz = S[A[i]].size();
        S[A[i]].push_back(S[A[i]][sz-1]+i+1);
    }
    cout << res << endl;
}