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

int n, m;
vector<ll> A, B, C, D;

bool f(ld x){
    vector<ld> X(n);
    vector<ld> Y(m);
    rep(i,n) X[i] = (ld)B[i] - x * A[i];
    rep(i,m) Y[i] = (ld)D[i] - x * C[i];
    vector<pair<ld,int>> E;
    rep(i,n){
        E.push_back({X[i],0});
    }
    rep(i,m){
        E.push_back({Y[i],1});
    }
    sort(all(E),greater<pair<ld,int>>());
    bool ok = false;
    int cnt = 0;
    ld sum = 0;
    rep(i,n+m){
        if(cnt == 5) break;
        auto[val,t] = E[i];
        if(t == 1) {
            if(ok) continue;
            ok = true;
            sum += val;
        }
        else{
            sum += val;
        }
        cnt++;
    }
    return sum >= 0;
}

int main(){
    fast_io
    cin >> n >> m;
    A = vector<ll>(n);
    B = vector<ll>(n);
    C = vector<ll>(m);
    D = vector<ll>(m);
    rep(i,n) cin >> A[i] >> B[i];
    rep(i,m) cin >> C[i] >> D[i];
    ld lef = 0, rig = 1e10;
    int cnt = 0;
    while(cnt < 200){
        ld mid = (lef + rig) / 2;
        if(f(mid)) lef = mid;
        else rig = mid;
        cnt++;
    }
    cout << fixed << setprecision(25) << lef << endl;
}