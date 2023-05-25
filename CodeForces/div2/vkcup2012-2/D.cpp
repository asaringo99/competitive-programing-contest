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

ll n, k, h;
vector<tuple<ll,ll,ll>> A;
vector<int> ans;

bool f(ld x){
    ll v = h * k;
    int m = k - 1;
    vector<int> res(k);
    rep(i,n){
        auto[w,t,id] = A[i];
        ld tim = (ld)v / t;
        if(tim <= x){
            v -= h;
            res[m--] = id + 1;
        }
        if(v == 0) {
            ans = res;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> k >> h;
    A = vector<tuple<ll,ll,ll>>(n);
    vector<ll> B(n), C(n);
    rep(i,n) cin >> B[i];
    rep(i,n) cin >> C[i];
    rep(i,n) A[i] = {B[i],C[i],i};
    sort(all(A), greater<tuple<ll,ll,ll>>());
    // rep(i,n){
    //     auto[w,t,id] = A[i];
    //     cout << w << " " << t << " " << id << endl;
    // }
    ld lef = 0, rig = 2e9;
    int cnt = 0;
    while(cnt < 200){
        ld mid = (lef + rig) / 2;
        if(f(mid)) rig = mid;
        else lef = mid;
        cnt++;
    }
    // cout << rig << endl;
    for(int u : ans) cout << u << " "; cout << endl;
}

int main(){
    fast_io
    solve();
}