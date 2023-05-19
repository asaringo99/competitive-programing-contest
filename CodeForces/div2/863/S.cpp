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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n, m;
    cin >> n >> m;
    set<ll> st;
    st.insert(-1e9);
    st.insert(1e9);
    rep(i,n){
        int a;
        cin >> a;
        st.insert(a);
    }
    rep(i,m){
        ll a, b, c;
        cin >> a >> b >> c;
        if(c <= 0){
            cout << "NO" << endl;
            continue;
        }
        ll val = 4 * a * c;
        auto it = st.upper_bound(b);
        ll x = *it; it--;
        ll y = *it;
        ll xx = (x-b)*(x-b);
        ll yy = (y-b)*(y-b);
        // cout << x << " " << y << " " << val << endl;
        // cout << xx << " " << yy << " " << val << endl;
        if(xx < val){
            cout << "YES" << endl;
            cout << x << endl;
            continue;
        }
        if(yy < val){
            cout << "YES" << endl;
            cout << y << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) {
        solve();
        if(i != z - 1) cout << endl;
    }
}