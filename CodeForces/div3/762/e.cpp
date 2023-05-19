#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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

int z ;

void solve(){
    int n;
    cin >> n;
    vector<ll> A(n);
    multiset<ll> st;
    rep(i,n) cin >> A[i], st.insert(A[i]);
    rep(i,n+1){
        if(st.count(i)) st.erase(st.find(i));
    }
    sort(A.begin(),A.end());
    ll res = 0;
    bool ok = true;
    rep(i,n+1){
        if(!ok){
            cout << -1 << " " ;
            continue;
        }
        int cnt = upper_bound(A.begin(),A.end(),i) - lower_bound(A.begin(),A.end(),i);
        if(cnt == 0){
            if(st.empty()){
                cout << res << " ";
                ok = false;
                continue;
            }
            cout << res << " ";
            auto it = st.upper_bound(i);
            if(it != st.begin()) it--;
            int v = *it;
            if(v < i){
                st.erase(it);
                res += i - v;
            }
            else{
                ok = false;
            }
        }
        else{
            cout << res + cnt << " ";
        }
    }
    cout << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}