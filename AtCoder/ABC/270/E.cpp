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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

ll n, k ;
ll A[202020];

int main(){
    fast_input_output
    cin >> n >> k ;
    priority_queue<P,vector<P>,greater<P>> que;
    rep(i,n) cin >> A[i];
    rep(i,n) if(A[i] > 0) que.push({A[i],i});
    ll cnt = 0;
    while(!que.empty()){
        auto[val, id] = que.top();
        ll t = que.size();
        if((val - cnt) * t >= k){
            cnt += k / t;
            k -= k / t * t;
            break;
        }
        while(!que.empty()){
            auto[tmp, i] = que.top();
            if(tmp != val) break;
            que.pop();
        }
        k -= t * (val - cnt);
        cnt = val;
    }
    rep(i,n){
        if(A[i] > cnt){
            A[i] -= cnt;
        }
        else{
            A[i] = 0;
        }
    }
    // cout << cnt << " " << k << endl;
    rep(i,n){
        if(k == 0) break;
        if(A[i] > 0) {
            A[i]--;
            k--;
        }
    }
    rep(i,n) cout << A[i] << " " ; cout << endl;
}