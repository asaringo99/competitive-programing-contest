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

int q, a, b;

int n;

set<ll> st;

int main(){
    fast_io
    cin >> q >> a >> b;
    st.insert(a+b);
    st.insert(a-b);
    st.insert(-1e18);
    st.insert(1e18);
    rep(i,q){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            st.insert(x-y);
            st.insert(x+y);
        }
        if(t == 2){
            ll res = 4e18;
            auto lt = st.lower_bound(x);
            lt--;
            ll vl = *lt;
            chmin(res,abs(x-vl));
            lt++;
            auto rt = st.lower_bound(y);
            ll vr = *rt;
            chmin(res,abs(y-vr));
            if(lt != rt) res = 0;
            cout << res << endl;
        }
    }
}