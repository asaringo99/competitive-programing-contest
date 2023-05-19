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
#define all(a) a.begin(), a.end()
#define endl "\n"

int n, m, k;
ll A[202020];
multiset<ll> st;
multiset<ll> ks;

int main(){
    // fast_input_output
    cin >> n >> m >> k;
    rep(i,n) cin >> A[i];
    ll sum = 0;
    if(k == 1){
        rep(i,n) cout << A[i] << " "; cout << endl;
        return 0;
    }
    if(k == n){
        ll sum = 0;
        rep(i,n) sum += A[i];
        cout << sum << endl;
        return 0;
    }
    for(int i = 0 ; i < m ; i++){
        ll a = A[i];
        st.insert(a);
        sum += A[i];
        if(st.size() > k) {
            auto it = st.end();
            it--;
            sum -= *it;
            ll x = *it;
            ks.insert(x);
            st.erase(it);
        }
    }
    cout << sum << " ";
    rrep(i,m,n){
        ll a = A[i-m];
        auto xt = ks.lower_bound(a);
        auto yt = st.lower_bound(a);
        if(ks.count(a)){
            ks.erase(xt);
            sum += A[i];
            st.insert(A[i]);
            auto jt = st.end(); jt--;
            sum -= *jt;
            ks.insert(*jt);
            st.erase(jt);
        }
        else if(st.count(a)){
            sum -= *yt;
            st.erase(yt);
            auto jt = ks.begin();
            st.insert(*jt);
            sum += *jt;
            ks.erase(jt);
            // cout << st.size() << " " << ks.size() << endl;
            sum += A[i];
            st.insert(A[i]);
            auto kt = st.end(); kt--;
            sum -= *kt;
            ks.insert(*kt);
            st.erase(kt);
        }
        cout << sum << " ";
    }
    cout << endl;
}