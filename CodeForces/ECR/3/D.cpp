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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

ll n, m, k, s;
vector<ll> A, B;
vector<pair<ll,ll>> V;

pair<bool,vector<pair<ll,ll>>> f(ll d){
    vector<pair<ll,ll>> X, Y;
    rep(i,d) X.push_back({A[i],i});
    rep(i,d) Y.push_back({B[i],i});
    sort(all(X));
    sort(all(Y));
    ll dl = X[0].first;
    ll dd = X[0].second;
    ll pn = Y[0].first;
    ll pd = Y[0].second;
    vector<tuple<ll,ll,ll>> S;
    rep(i,m){
        ll t = V[i].first;
        ll u;
        int dy;
        if(t == 1){
            u = V[i].second * dl;
            dy = dd;
        }
        else{
            u = V[i].second * pn;
            dy = pd;
        }
        S.push_back({u,i,dy});
    }
    sort(all(S));
    vector<pair<ll,ll>> res;
    ll sum = 0;
    rep(i,k){
        auto[val,id, dy] = S[i];
        sum += val;
        res.push_back({id+1,dy+1});
    }
    if(sum <= s) return {true,res};
    return {false,{}};
}

void solve(){
    cin >> n >> m >> k >> s;
    A.resize(n);
    B.resize(n);
    V.resize(m);
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    rep(i,m) cin >> V[i].first >> V[i].second;
    ll lef = 0, rig = n + 1;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2;
        auto [ok, vec] = f(mid);
        if(ok) rig = mid;
        else lef = mid;
    }
    if(rig == n + 1){
        cout << -1 << endl;
        return;
    }
    auto[ok,vec] = f(rig);
    cout << rig << endl;
    for(auto [id, dy] : vec){
        cout << id << " " << dy << endl;
    }
}

int main(){
    fast_io
    solve();
}