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

ll n, m, k;
ld A[101010], B[101010];
ld C[101010], D[101010];

bool f(ld x){
    x /= 100;
    vector<ld> X;
    rep(i,m){
        ld val = - C[i] * (1 - x) + D[i] * x;
        X.push_back(val);
    }
    sort(all(X));
    ll res = 0;
    rep(i,n){
        ld val = - B[i] * x + A[i] * (1 - x);
        auto it = upper_bound(all(X),val);
        res += (ll)(it - X.begin());
    }
    // cout << res << " " << k << " " << x << endl;
    return res >= k;
}

int main(){
    fast_io
    cin >> n >> m >> k;
    rep(i,n) cin >> A[i] >> B[i];
    rep(i,m) cin >> C[i] >> D[i];
    int cnt = 0;
    ld lef = 0, rig = 100;
    while(cnt < 200){
        ld mid = (lef + rig) / 2;
        // cout << mid << endl;
        if(f(mid)) lef = mid;
        else rig = mid;
        cnt++;
    }
    cout << fixed << setprecision(25) << lef << endl;
}